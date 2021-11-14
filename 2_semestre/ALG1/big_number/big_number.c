#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"big_number.h"

B_NUMBER* create(){
    B_NUMBER* b_n;

    b_n = malloc(sizeof(B_NUMBER));
    b_n->nodes = 0;
    b_n->signal = -1;
    b_n->start = NULL;
    b_n->end = NULL;

    return b_n;
}

void liberate(B_NUMBER* b_n){
    assert(b_n != NULL);

    NODE* aux = b_n->start;

    while(aux != NULL){
        b_n->start = b_n->start->next;
        free(aux);
        aux = b_n->start;
    }

    free(b_n);
}

int insert(B_NUMBER* b_n, int node){
    b_n->nodes++;
    assert(b_n != NULL);

    NODE* p = malloc(sizeof(NODE));
    p->info = node;
    p->next = NULL;
    p->prev = NULL;

    if(b_n->start == NULL){
        b_n->start = p;
        b_n->end   = p;
    }else{
        b_n->end->next = p;
        b_n->end = p;
    }

    return 1;
}

B_NUMBER* SUM(B_NUMBER* num1, B_NUMBER* num2){
    assert(num1 != NULL);
    assert(num2 != NULL);

    B_NUMBER* sum = create();
        
    NODE* aux1 = num1->end;
    NODE* aux2 = num2->end;
    int i = 0, j;

    if(num1->nodes > num2->nodes){
        sum->nodes = num1->nodes + 1;
        j = num1->nodes;
    }else{
        sum->nodes = num2->nodes + 1;
        j - num2->nodes;
    }

    //criando os nós da lista soma
    while (i++ <= sum->nodes)
        insert(sum, 0);
    
    NODE* auxSum = sum->end;
    while (j-- > num2->nodes){
        auxSum->info = aux1->info;

        aux1   = aux1->prev;
        auxSum = auxSum->prev;
    }

    while (j-- > num1->nodes){
        auxSum->info = aux2->info;

        aux2   = aux2->prev;
        auxSum = auxSum->prev;
    }
        
    while (aux1 != NULL && num2 != NULL){
        auxSum->info = aux1->info + aux2->info;
    
        auxSum = auxSum->prev;
        aux1   = aux1->prev;
        aux2   = aux2->prev;
    }

    return sum;
}

int BIG(B_NUMBER* num1, B_NUMBER* num2){
    assert(num1 != NULL);
    assert(num2 != NULL);

    if(num1->signal == 1 && num2->signal == 0) //if num1 is negative and num2 is not
        return 0;
    else if(num1->signal == 0 && num2->signal == 1) //if num2 is negative and num1 is not
        return 1;

    if(num1->nodes > num2->nodes)
        return 1;
    if(num1->nodes < num2->nodes)
        return 0;

    NODE* aux1 = num1->start;
    NODE* aux2 = num2->start;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->info > aux2->info)
            return 1;
        else if(aux1->info < aux2->info)
            return 0;

        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    if(aux1 == NULL && aux2 != NULL)      //if num1 still has numbers and num2 does not, num1 > num1
        return 0;
    else if(aux1 != NULL && aux2 == NULL) //if num2 still has numbers and num1 does not, num1 > num2
        return 1;
}

int SML(B_NUMBER* num1, B_NUMBER* num2){
    assert(num1 != NULL);
    assert(num2 != NULL);

    if(num1->signal == 1 && num2->signal == 0) //if num1 is negative and num2 is not, num1 < num2
        return 1;
    else if(num1->signal == 0 && num2->signal == 1) //if num2 is negative and num1 is not, num1 > num2
        return 0;

    if(num1->nodes < num2->nodes)
        return 1;
    if(num1->nodes > num2->nodes)
        return 0;

    NODE* aux1 = num1->end;
    NODE* aux2 = num2->end;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->info > aux2->info)
            return 0;
        else if(aux1->info < aux2->info)
            return 1;

        aux1 = aux1->prev;
        aux2 = aux2->prev;
    }

    if(aux1 == NULL && aux2 != NULL)      //if num1 still has numbers and num2 does not, num1 > num2
        return 1;
    else if(aux1 != NULL && aux2 == NULL) //if num2 still has numbers and num1 does not, num2 > num1
        return 0;
}

int EQL(B_NUMBER* num1, B_NUMBER* num2){
    assert(num1 != NULL);
    assert(num2 != NULL);

    if(num1->signal != num2->signal)
        return 0;

    NODE* aux1 = num1->start;
    NODE* aux2 = num2->start;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->info != aux2->info)
            return 0;

        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    if(aux1 != NULL && aux2 != NULL)
        return 0;

    return 1;
}

int print(B_NUMBER* b_n){
    assert(b_n != NULL);

    if(b_n->start == NULL)
        return 0;

    printf("%d   ", b_n->nodes);

    if(b_n->signal == 1)
        printf("-");

    NODE* p = b_n->start;
    printf("%d", p->info);

    p = p->next;
    while(p != NULL){
        if(p->info < 1000){
            printf("0");
            if(p->info < 100){
                printf("0");
                if(p->info < 10){
                    printf("0");    
                }
            }
        }
        printf("%d", p->info);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int inverted_print(B_NUMBER* b_n){
    assert(b_n != NULL);

    if(b_n->start == NULL)
        return 0;

    NODE* p = b_n->end;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->prev;
    }
    printf("\n");
    return 1;
}
