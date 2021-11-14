#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"polynomial.h"

LIST_P* create_list(){
    LIST_P* list_p = malloc(sizeof(LIST_P));

    assert(list_p != NULL);

    list_p->start = NULL;
    list_p->end   = NULL;

    return list_p;
}

NODE* atom(char x, DATA value){
    NODE* node = (NODE*)malloc(sizeof(NODE));

    node->type = 0;
    node->next = NULL;
    node->value = value;
    node->vars.atom = x;

    return node;
}

NODE* sublist(NODE* sublist, DATA value){
    assert(sublist != NULL);
    NODE* node = (NODE*)malloc(sizeof(NODE));

    node->type = 1;
    node->next = NULL;
    node->value = value;
    node->vars.sublist = sublist;

    return node;
}

NODE* concat_vars(NODE* node_1, NODE* node_2){
    assert(node_1 != NULL);
    assert(node_2 != NULL);

    node_1->next = node_2;

    return node_1;
}

void add_in_the_list(LIST_P* list_p, NODE* node){
    assert(list_p != NULL);
    assert(node != NULL);

    if(list_p->start == NULL){
        list_p->start = node;
        list_p->end   = node;
    }else{
        list_p->end->next = node;
        list_p->end = node;
    }
}

/* Check which polynomial has the most terms */
int more_terms(LIST_P* list_p){
    assert(list_p != NULL);
    int polynomial = 1, moreTerms = 1;

    NODE* node = list_p->start;
    while (node != NULL){
        
        NODE* aux = NULL;
        if(node->type == 1)
            aux = node->vars.sublist;

        while (aux != NULL){
            polynomial++;
            
            aux = aux->next;
        }

        node = node->next;

        if(polynomial > moreTerms)
            moreTerms = polynomial;

        polynomial = 1;
    }
    
    return moreTerms;
}

LIST_P* create_list_sum(LIST_P* list_p, int* moreTerms){
    assert(list_p != NULL);

    LIST_P* list_p_sum = create_list();

    NODE* node =  list_p->start;

    //find out how many nodes the summation polynomial should have
    *moreTerms = more_terms(list_p);

    NODE* last_var = NULL, *first_var;
    
    int j = 1;
    while (j < *moreTerms){
        NODE* aux = atom('x', 0); //create the node for the new variable
        
        if(last_var != NULL) //concatenate the variables
            last_var = concat_vars(last_var, aux);
        else                 //save the first variable to create the sublist later
            first_var = aux;

        last_var = aux;
        
        j++;
    }

    NODE* polynomial;
    //checks if the polynomial has only one term
    if(node->type == 1)
        polynomial = sublist(first_var, 0);
    else    
        polynomial = atom('x', 0);

    add_in_the_list(list_p_sum, polynomial);

    return list_p_sum;
}

LIST_P* calculate(LIST_P* list_p){
    int moreTerms = 0;
    LIST_P* list_p_sum = create_list_sum(list_p, &moreTerms);
    
    NODE* node_p = list_p->start;
    NODE* node_p_sum = list_p_sum->start;

    while (node_p != NULL){
        node_p_sum->value += node_p->value; //primary node

        NODE* aux_p = NULL;
        if(node_p->type == 1)               //check if there really is a sublist
            aux_p   = node_p->vars.sublist;
        
        NODE* aux_p_s = NULL;   
        if(node_p_sum->type == 1)           //check if there really is a sublist
            aux_p_s = node_p_sum->vars.sublist;
            
        while (aux_p != NULL){              //sums all variable nodes
            aux_p_s->value += aux_p->value;
            
            aux_p   = aux_p->next;
            aux_p_s = aux_p_s->next;
        }

        node_p = node_p->next;
    }

    return list_p_sum;
}

void liberate(NODE* node){
    NODE* aux;

    while (node != NULL){
        if(node->type == 1)
            liberate(node->vars.sublist);

        aux = node;
        node = node->next;
        free(aux);
        aux = NULL;
    }
}

void liberate_list(LIST_P* list_p){
    liberate(list_p->start);
    assert(list_p != NULL);

    free(list_p);
    list_p = NULL;
}

void prints(NODE* node){
    if(node == NULL)
        return;

    while (node != NULL){

        printf("%d", node->value);
        
        if(node->next != NULL)
            printf(",");

        node = node->next;
    }
}

void print(NODE* node){
    while (node != NULL)
    {
        printf("(%d", node->value);
        if(node->type == 1){
            printf(",");
            prints(node->vars.sublist);
        }
        printf(")\n");
        node = node->next;  
    }
}


int receive_polynomial(LIST_P* list_p){
    assert(list_p != NULL);
    char c = getchar();

    int number;
    scanf("%d", &number);
    int first_value = number;
    
    c = getchar();
    c = getchar();

    //checking if it is a unit polynomial
    if(c == '\r' || c == '\n' || c == EOF){
        NODE*polynomial = atom('x', first_value);
        add_in_the_list(list_p, polynomial);
        
        clear_buffer();
        return 0;
    }

    ungetc(c, stdin);

    NODE* last_var = NULL, *first_var = NULL;
    
    while (c != ')'){
        scanf("%d", &number);

        NODE* aux = atom('x', number); //create the node for the new variable
        
        if(last_var != NULL) //concatenate the variables
            last_var = concat_vars(last_var, aux);
        else{                //save the first variable to create the sublist later
            free(first_var);
            first_var = aux;
        }
        last_var = aux;
        c = getchar();
    } 

    NODE* polynomial;
    polynomial = sublist(first_var, first_value);
        
    add_in_the_list(list_p, polynomial);
    
    clear_buffer();
    
    return 0;
}

int clear_buffer(){
    char c;
    c = getchar();
    if(c == '\r') c = getchar();
    
    c = getchar();
    if(c == EOF) return 1;
    else ungetc(c, stdin);

    return 0;
}