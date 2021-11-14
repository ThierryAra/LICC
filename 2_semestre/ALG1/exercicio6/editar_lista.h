typedef int elem;
typedef struct lista Lista_t;

/*  Aloca espaco na memoria para receber uma lista */
Lista_t* criar(int tamanho);

/*  Libera o espaco armazenado para a lista na memoria */
void libera(Lista_t* lista);

/*  Insere o elemento 'x' na lista          */
void insere(Lista_t* lista, elem x);

/*  Exibe todos os elementos da lista       */
void imprime(Lista_t* lista);

/*  Retorna uma lista com um shift <<, o primeiro elemento vai para a ultima */
void inverte(Lista_t* lista);