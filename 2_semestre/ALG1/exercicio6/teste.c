#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef LISTAH
#define LISTAH
#include"editar_lista.h"
#endif

typedef struct no no_t;

struct no{
    elem info;
    struct no *prox;
};

struct lista{
    struct no *inicio;
    struct no *fim;
    int tam;
};

Lista_t* criar(int tamanho){
    Lista_t* lista;

    lista = malloc(tamanho * sizeof(Lista_t));
    assert(lista != NULL);

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void libera(Lista_t* lista){
    if(lista != NULL){
        no_t* p = lista->inicio;

        while (p != NULL){
            lista->inicio = p->prox;
            free(p);
            p = lista->inicio;
        }
     
        free(lista);
    }
}

int retira(Lista_t* lista, elem x){
    assert(lista != NULL);

    no_t* p = lista->inicio;
    no_t* ant = NULL;

    while (p != NULL){
        if(p->info == x){
            //1 caso - remover do inicio
            if(p == lista->inicio){
                lista->inicio = lista->inicio->prox;
                free(p);
            //2 caso - remover do fim
            } else if(p == lista->fim){
                lista->fim       = ant;
                lista->fim->prox = NULL;
                free(p);
            //3 caso - remover do meio
            } else{
                ant->prox = p->prox;
                free(p);
            }

            (lista->tam)--;
            return 1;
        } else{
            ant = p;
            p   = p->prox;
        }
    }

    return 0;
}

int tamanho(Lista_t* lista){
    assert(lista != NULL);

    return (lista->tam);
}

int esta_na_lista(Lista_t* lista, elem x){
    assert(lista != NULL);
    
    no_t* p = lista->inicio;

    while(p != NULL){
        if(p->info == x)
            return 1;
        else
            p = p->prox;
    }
    
    return 0;
}

void insere(Lista_t* lista, elem x){
    assert(lista != NULL);

    no_t* p = malloc(sizeof(no_t));

    p->info = x;
    p->prox = NULL;

    //1 caso - lista vazia
    if(lista->inicio == NULL)
        lista->inicio = p;

    //2 caso - lista com pelo menos 1 elemento 
    else
        lista->fim->prox = p;

    lista->fim = p;
    (lista->tam)++;
}

void imprime(Lista_t* lista){
    assert(lista != NULL);

    no_t* p = lista->inicio;

    while (p != NULL){
        printf("%d ", p->info);

        p = p->prox;
    }
    printf("\n");
}

void inverte(Lista_t* lista){
    assert(lista != NULL);
    no_t* p = lista->inicio->prox;

    elem x_fim = lista->fim->info;
    
    //lista->inicio->info = (elem)x_fim;
    //printf("\nnovo inicio %d inicio-prox %p lista fim %p", lista->inicio->info, lista->inicio->prox, lista->fim->prox);
    
    no_t* ant  = lista->inicio; 
    elem x_ant = 0;
    elem x_prx = lista->inicio->prox->info; 
    elem x_atu = x_prx;

    while (p != NULL){
        x_ant   = ant->info;
        x_prx   = p->info;
        ant     = p;
        printf("%d", x_ant);
        p->info = x_atu;

        x_atu   = x_prx;
        p       = p->prox;
        //printf("ANT %d %p P %d %p\n", ant->info, ant->prox, p->info, p->prox);
    }
     
    lista->inicio->info = x_fim;
    printf("\nFIM %d %p\n", lista->fim->info, lista->fim->prox);
} 

int main(){
    Lista_t *lista;


    int qtd_testes;
    scanf("%d", &qtd_testes);

    while (qtd_testes > 0){
        int tam_lista;
        scanf("%d", &tam_lista);
        //printf("\nTAM LISTA %d\n", tam_lista);
        lista = criar(tam_lista);

        int inversor;
        scanf("%d", &inversor);
        //printf("\nINVERSOR %d\n", inversor);

        while (tam_lista > 0){
            int dado;
            scanf("%d", &dado);

            insere(lista, dado);
            tam_lista--;
        }
        
        //while (inversor > 0){
            inverte(lista);
           // inversor--;
        //}
        

        imprime(lista);
        libera(lista);
        qtd_testes--;
    }
    
    return 0;
}
