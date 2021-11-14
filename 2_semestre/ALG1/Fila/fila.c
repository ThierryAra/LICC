#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"fila.h"

struct fila {
    int inicio, fim, total;
    elem itens[TAMFILA];
};

fila_t* criar(){
    fila_t *f;

    f = malloc(sizeof(fila_t));
    assert(f != NULL);

    f->total = 0;
    f->inicio = 0;
    f->fim = 0;

    return f;
}

int is_empty(fila_t *f){
    assert(f != NULL);

    if (f->total == 0)
        return 1;
    else
        return 0;
}

int is_full(fila_t *f){
    assert(f != NULL);

    if (f->total == TAMFILA)
        return 1;
    else
        return 0;
}

int insert(fila_t* f, elem x){
    if (is_full(f) == 1)
        return 0;

    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % TAMFILA;
    (f->total)++; 
    
    return 1;
}

int remover(fila_t* f, elem* x){
     if (is_empty(f) == 1)
        return 0;

    *x = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAMFILA;
    (f->total)--; 
    return 1;
}

void excluir(fila_t* f){
    if(f != NULL)
        free(f);
}