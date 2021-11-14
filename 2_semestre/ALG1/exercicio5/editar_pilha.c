#include<stdio.h>
#include<stdlib.h>
#include"editar_pilha.h"
#include"editar_texto.h"

PILHA* criar_pilha(){
    PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));
    if(pilha == NULL)
        return NULL;

    //pilha->itens = (char*)malloc((QTD_ABERTURA * 2) * sizeof(char));
    pilha->itens = malloc(sizeof(char));
    if(pilha == NULL){
        return NULL;
        printf("FALHA MALLOC");
    }

    pilha->topo = -1;
    return pilha;
}

void destruir(PILHA* pilha){
    if(pilha != NULL){
        free(pilha->itens);
        free(pilha);
    }

    pilha = NULL;
}   

int cheia(PILHA* pilha){
    if(pilha == NULL)
        return 0;

    if(pilha->topo >= (QTD_ABERTURA * 2))
        return 1;
    else
        return 0;
}

int vazia(PILHA* pilha){
    if(pilha == NULL)
        return 0;

    if(pilha->topo == -1){
        pilha->itens[0] = EOF;
        return 1;
    }
    else
        return 0;
}

int push(PILHA* pilha, char dado){
    if(pilha == NULL)
        return 0;

    if (cheia(pilha) == 1)
        return 0;

    pilha->topo += 1;
    pilha->itens = realloc(pilha->itens, (pilha->topo + 1) * sizeof(char));
    pilha->itens[pilha->topo] = dado;
    return 1;
}

int pop(PILHA* pilha){
    if(pilha == NULL)
        return 0;
    
    if(vazia(pilha))
        return -1;

    pilha->topo -= 1;
    
    return 1;
}

int top(PILHA* pilha, char* dado){
    if(pilha == NULL)
        return 0;

    if(vazia(pilha))
        return 0;

    (*dado) = pilha->itens[pilha->topo]; 
    return 1;
}
