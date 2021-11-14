#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef LISTAH
#define LISTAH
#include"lista_e.h"
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

Lista_t* criar(){
    Lista_t* lista;

    lista = malloc(sizeof(Lista_t));
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

    //lista com apenas elementos distintos
    if(esta_na_lista(lista, x))
        return;

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

Lista_t* inverte(Lista_t* lista){
    assert((lista) != NULL);
    
    no_t* p_l = (lista)->inicio;
    no_t* ant = NULL;
    
    Lista_t* lista_inversa = criar();
    lista_inversa->inicio = (lista)->fim;
    no_t* p_li = lista_inversa->inicio;

    while (p_l->prox != NULL){
        while (p_l != NULL){
            if(p_l == lista->fim){
                if(p_li != (lista)->inicio){
                   /*  p_li->prox = p_l;
                    lista_inversa->fim = p_l;
                    lista_inversa->fim->prox = NULL;

                    p_l = NULL;
                    break;
                } else{ */
                    p_li->prox = ant;
                    p_li       = ant;
                }

                ant->prox = NULL;
                (lista)->fim = ant;
                break;
            }

            if(p_l != NULL){
                ant = p_l;
                p_l = p_l->prox;
            }
        }
        p_l = (lista)->inicio;
    }
    
    //libera(lista);
    
    return lista_inversa;
}



