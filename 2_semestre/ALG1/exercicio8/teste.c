#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define TAM 200

struct person{
    int ID;
    char name[50];
};

typedef struct no{
    struct person info;
    int next;
}no_t;

struct banco{
    no_t v[TAM];
    int start, end, p_empty;
};

typedef struct banco banco_t;
typedef struct person person_t;

void liberar_no(banco_t* mem_bank, int pos){
    assert(mem_bank != NULL);
    assert(pos >= 0 && pos < TAM);

    mem_bank->v[pos].next = mem_bank->p_empty;
    mem_bank->p_empty = pos;
}

int obter_no(banco_t* mem_bank, int ordem, person_t x){
    assert(mem_bank != NULL);

    if(mem_bank->p_empty == -1)
        return -1;
    else if(ordem == 0){ //valor no final
        int pos = mem_bank->p_empty;
        mem_bank->p_empty = mem_bank->v[pos].next;
        mem_bank->v[pos].next = -1;

        return pos;
    }else if(ordem == 1){ //valor ordenado
        int i = mem_bank->start, pos;
        while(i != -1){

            if(mem_bank->v[i].info.ID > x.ID){
                pos = i;
                printf("pos %d\n", pos);
                return pos;
            }

            i = mem_bank->v[i].next;
        }

        pos = mem_bank->p_empty;
        return (pos);
    }
}

banco_t* criar(){
    int i;

    banco_t* mem_bank = malloc(sizeof(banco_t));

    for (i = 0; i < TAM - 1; i++){
        mem_bank->v[i].next = i + 1;
    }
    
    mem_bank->v[i].next = -1;
    mem_bank->end = 0;
    mem_bank->start = -1;
    mem_bank->p_empty = 0;
}

int esta_vazio(banco_t* mem_bank){
    assert(mem_bank != NULL);

    return (mem_bank->start == -1);
}

int esta_cheio(banco_t* mem_bank){
    assert(mem_bank != NULL);

    return (mem_bank->start == -1);
}

int inserir(banco_t* mem_bank, person_t x){
    int pos = obter_no(mem_bank, 0, x);
    
    if(pos == -1)
        return 0;

    mem_bank->v[pos].info = x;
    
    if(mem_bank->end != -1)
        mem_bank->v[mem_bank->end].next = pos;
    
    mem_bank->end = pos;

    if(mem_bank->start == -1)
        mem_bank->start = pos;

    return 1;
}

int inserir_ordenado(banco_t* mem_bank, person_t x){
    int pos = obter_no(mem_bank, 1, x);
    
    if(pos == -1)
        return 0;

    if(pos == mem_bank->p_empty){
        inserir(mem_bank, x);
        return 1;
    
    }

    int i = mem_bank->v[pos].next;
    person_t info_ant  = mem_bank->v[pos].info;
    person_t info_prox = mem_bank->v[pos].info;

    //passa todos (menos o último) valores para uma posição a frente
    while (i != -1){
        info_prox = mem_bank->v[i].info;
        mem_bank->v[i].info = info_ant;  

        i = mem_bank->v[i].next;  
        info_ant = info_prox;
    }

    mem_bank->v[pos].info = x;
    
    //adiciona uma nova posicao
    mem_bank->v[mem_bank->end].next = mem_bank->p_empty; 

    //p_empty passa a valer a proxima posicao da lista de vazios
    int ant = mem_bank->p_empty; 
    mem_bank->p_empty = mem_bank->v[ant].next;
    
    //seta a nova posicao para o final
    mem_bank->v[ant].info = info_prox;
    mem_bank->v[ant].next = i;
    mem_bank->end = ant;
    
    return 1;
}

int remover(banco_t* mem_bank, person_t* x){
    assert(mem_bank != NULL);

    if(mem_bank->start == -1)
        return 0;

    *x = mem_bank->v[mem_bank->start].info;

    int pos = mem_bank->start;
    mem_bank->start = mem_bank->v[pos].next;
    liberar_no(mem_bank, pos);

    return 1;
}

void liberar(banco_t* mem_bank){
    assert(mem_bank != NULL);

    free(mem_bank);

    mem_bank = NULL;
}


int obter_no_(banco_t* mem_bank, int ordem, int ID, int* penultimate){
    assert(mem_bank != NULL);

    if(mem_bank->p_empty == -1)
        return -1;
    else if(ordem == 0){ //valor no final
        int pos = mem_bank->p_empty;
        mem_bank->p_empty = mem_bank->v[pos].next;
        mem_bank->v[pos].next = -1;

        //printf("prox no: %d |\n", mem_bank->v[pos].next);
        return pos;
    }else if(ordem == 1){ //valor ordenado
        int i = mem_bank->start, pos;
        *penultimate = -1;
        while(i != -1){
            
            if(mem_bank->v[i].info.ID > ID){
                pos = i;
                //printf("pos %d | ", pos);
                return pos;
            }

            *penultimate = i;
            i = mem_bank->v[i].next;
        }

        pos = mem_bank->p_empty;
        return (pos);
    }
}

int insert(banco_t* mem_bank, person_t x){
    int pos = mem_bank->p_empty;
    mem_bank->p_empty = mem_bank->v[pos].next;
    mem_bank->v[pos].next = -1;
    
    mem_bank->v[pos].info = x;
    
    //if(mem_bank->end != -1)
        //mem_bank->v[mem_bank->end].next = pos;
    
    //printf("prox inserir: %d |\n", mem_bank->v[pos].next);

    if(mem_bank->start == -1)
        mem_bank->start = pos;
    else
        mem_bank->v[mem_bank->end].next = pos;


    mem_bank->end = pos;
    return 1;
}

int insert_sorted(banco_t* mem_bank, person_t x){
    assert(mem_bank != NULL);

    int penultimate;
    int pos = obter_no_(mem_bank, 1, x.ID, &penultimate);
    
    if(pos == mem_bank->p_empty){
        printf("\n");
        insert(mem_bank, x);
        return 1;

    }else if(pos == mem_bank->start){
        int empty = mem_bank->p_empty;

        mem_bank->v[empty].info = x;
        
        mem_bank->v[empty].next = mem_bank->start;

        mem_bank->start = empty;
        
    }else{
        int empty = mem_bank->p_empty;

        mem_bank->v[penultimate].next = empty;
        mem_bank->v[empty].info = x;
        
        mem_bank->p_empty = mem_bank->v[empty].next;

        mem_bank->v[empty].next = pos;
    }
    
    return 1;
}

int search_ID(banco_t* mem_bank, int ID, int* penultimate){
    if(esta_vazio(mem_bank))
        return -2;
    
    int  i = mem_bank->start;
    *penultimate = -1;
    
    while(i != -1){
        if(mem_bank->v[i].info.ID == ID)
            return i;
        
        *penultimate = i;
        i = mem_bank->v[i].next;
    }
    
    return -2;
}

int remove_ID(banco_t* mem_bank, int ID){
    assert(mem_bank != NULL);

    printf("chgeu\n");
    if(mem_bank->start == -1)
        return -1;

    int penultimate;
    int pos = search_ID(mem_bank, ID, &penultimate);
    printf("POSICAO %d", pos);
    if(pos == -2)
        return 0;

    if(pos == mem_bank->start)
        mem_bank->start = mem_bank->v[mem_bank->start].next;
    else if(pos == mem_bank->end){
        //printf("\npenultimo: %d\n", penultimate);
        mem_bank->end = penultimate;
        mem_bank->v[penultimate].next = -1;
    }      
    else
        mem_bank->v[penultimate].next = mem_bank->v[pos].next;

    mem_bank->v[pos].next = mem_bank->p_empty;
    mem_bank->p_empty = pos;
    //liberar_no(mem_bank, pos);
    return 1;
}

int print_people(banco_t* mem_bank){
    if(esta_vazio(mem_bank)){
        return 0;
    }

    int i = mem_bank->start;

    while (i != -1){
        printf("i: %d | ", i);
        printf("%d, ", mem_bank->v[i].info.ID);
        printf("%s; ", mem_bank->v[i].info.name);
        i = mem_bank->v[i].next;
    }
    
    printf("\n");
    return 1;
}

int main(){

    char op[8];

    banco_t* mem_bank = criar();
    //PERSON person = malloc(sizeof(PERSON));
    person_t person;
    
    char end = getchar();

    while(end != EOF){
        ungetc(end, stdin);
        scanf("%s", op);
        end = getchar();
        //printf("%s \n", op);
        if(strcmp(op, "INSERE") == 0){
            scanf("%d", &person.ID);
            end = getchar();
            printf("%d, ", person.ID);
            scanf("%[^\n]", person.name);
            end = getchar();
            printf("%s;\n", person.name);

            int penultimate;
            if(search_ID(mem_bank, person.ID, &penultimate) == -2){
                insert_sorted(mem_bank, person);
                //printf("inseri");
            }
            else
                printf("INVALIDO\n");

        }else if(strcmp(op, "REMOVE") == 0){
            int ID;
            scanf("%d", &ID);
            getchar();
            //printf("\nID = %d\n", ID);
            remove_ID(mem_bank, ID);
            if(remove_ID(mem_bank, ID) == 0)
                printf("INVALIDO\n");

        }else if(strcmp(op, "IMPRIMIR") == 0){
            getchar();
            if(print_people(mem_bank) == 0)
                printf("VAZIA\n");
        } 

        end = getchar();
        if(end == '\n'){
            //printf("achei um \\n");
            if(end == '\r'){
                end = getchar();
                printf(" achei 1 \\r");
            }
        }
    }
    
    liberar(mem_bank);
    return 0;
}