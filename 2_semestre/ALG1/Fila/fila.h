#define TAMFILA 10

typedef int elem;
typedef struct fila fila_t;

fila_t* criar();

int is_empty(fila_t* f);

int is_full(fila_t* f);

int insert(fila_t* f, elem x);

int remover(fila_t* f, elem* x);

void excluir(fila_t* f);