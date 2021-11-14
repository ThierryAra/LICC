#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_pilha.h"

struct pilha_t {
    void** itens;
    int topo;
    int tamanho_elem;
};


PILHA* criar_pilha(int tam_elem){
    PILHA* pilha = (void*)malloc(sizeof(PILHA));
    assert(pilha != NULL);

    pilha->itens = (void**)malloc(sizeof(void*) * tam_elem);
    assert(pilha->itens != NULL); 

    pilha->topo = -1;
    pilha->tamanho_elem = tam_elem;
}

void destruir(PILHA* pilha){
    while(!vazia(pilha)){
        free(pilha->itens[pilha->topo]);
        pilha->topo -= 1;
    }

    if(pilha != NULL){
        free(pilha->itens);
        free(pilha);
    }

    pilha = NULL;
}   

int cheia(PILHA* pilha){
    assert(pilha != NULL);

    if(pilha->topo > 100)
        return 1;
    else
        return 0;
}

int vazia(PILHA* pilha){
    assert(pilha != NULL);

    if(pilha->topo == -1)
        return 1;
    else
        return 0;
}

int push(PILHA* pilha, void* dado){
    assert(pilha != NULL);

    if (cheia(pilha) == 1)
        return -1;

    pilha->topo += 1;
    pilha->itens[pilha->topo] = (void*)malloc(pilha->tamanho_elem);
    memcpy(pilha->itens[pilha->topo], dado, pilha->tamanho_elem);
    printf("\n%d\n\n", pilha->topo);
    return 1;
}

int pop(PILHA* pilha, void* dado){
    assert(pilha != NULL);

    if (vazia(pilha) == 1)
        return -1;

    memcpy(dado, pilha->itens[pilha->topo], pilha->tamanho_elem);
    free(pilha->itens[pilha->topo]);
    pilha->topo -= 1;
    
    return 1;
}

int top(PILHA* pilha, void* dado){
    assert(pilha != NULL);

    if(vazia(pilha) == 1)
        return -1;

    memcpy(dado, pilha->itens[pilha->topo], pilha->tamanho_elem);

    return 1;
}
