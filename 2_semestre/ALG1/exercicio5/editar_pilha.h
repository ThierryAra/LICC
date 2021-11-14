#ifndef DEFINICAO_PILHA 
#define DEFINICAO_PILHA 

typedef struct pilha_t{
    char* itens;
    int topo;
}PILHA;

/*  Retorna um ponteiro inicializado para armazenar uma pilha   */
PILHA* criar_pilha();

/*  Limpa a memoria armazenada para os dados da pilha e para a apilha   */
void destruir(PILHA* pilha);

/*  Verifica se a pilha esta cheia
    RETORNO:
        1 - cheio
        0 - nao cheio            */
int cheio(PILHA* pilha);

/* Verifica se a pilha esta vazia
    RETORNO:
        1 - vazia
        0 - nao vazia            */
int vazia(PILHA* pilha);

/*  Adiciona um dado na pilha
    RETORNO:
        1 - Adicionado com sucesso
        0 - Erro de memoria/pilha cheia      */
int push(PILHA* pilha, char dado);

/*  Remove um dado da pilha
    RETORNO:
        1 - Removido com sucesso
        0 - Erro de memoria
       -1 - Pilha vazia       */
int pop(PILHA* pilha);

/* Atribui ao dado o valor que esta no topo da pilha
    RETORNO:
        1 - Atribuido com sucesso
        0 - Erro de memoria/lista vazia           */
int top(PILHA* pilha, char* dado);

#endif