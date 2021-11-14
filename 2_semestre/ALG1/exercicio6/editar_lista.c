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

void insere(Lista_t* lista, elem x){
    assert(lista != NULL);

    no_t* p = malloc(sizeof(no_t));

    p->info = x;
    p->prox = NULL;

    if(lista->inicio == NULL)
        lista->inicio = p;
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
    no_t* p    = lista->inicio->prox;

    elem x_fim = lista->fim->info;
    
    no_t* ant  = lista->inicio; 
    
    elem x_ant = 0;
    elem x_prx = lista->inicio->info; 
    elem x_atu = x_prx;

    while (p != NULL){
        x_ant   = ant->info; //info da posicao a
        x_prx   = p->info;   //info da posicao a+1    
        
        p->info = x_atu;     //info de a+1 recebe x_atu, que corresponde ao info substituido de a+1 
        
        x_atu   = x_prx;     //atual passa a valer a info de a+1, para que nao se perca o dado

        ant     = p;         //ponteiro do nó ant passa a valer o do no a+1
        p       = p->prox;   //ponteiro do nó  p  passa a valer o do no a+1+1
    }
     
    lista->inicio->info = x_fim;
} 

