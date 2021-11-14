typedef struct pilha_t PILHA;

PILHA* criar_pilha(int tam_elem);

void destruir(PILHA* pilha);

int cheio(PILHA* pilha);

int vazia(PILHA* pilha);

int push(PILHA* pilha, void* dado);

int pop(PILHA* pilha, void* dado);

int top(PILHA* pilha, void* dado);