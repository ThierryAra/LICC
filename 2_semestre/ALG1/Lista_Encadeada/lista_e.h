typedef int elem;
typedef struct lista Lista_t;

/*  Aloca espaco na memoria para receber uma lista */
Lista_t* criar();

/*  Libera o espaco armazenado na memoria, para a lista */
void libera(Lista_t* lista);

/*  Retira o elemento 'x', caso esteja presente na lista 
    RETORNO:
        1 - retirado com sucesso
        0 - nao encontrado                              */
int retira(Lista_t* lista, elem x);

/*  Retorna a quantidade de elementos da lista */
int tamanho(Lista_t* lista);

/*  Verifica se o elemento 'x' esta na lista
    RETORNO:
        1 - encontrado na lista
        0 - nao encontrado                  */
int esta_na_lista(Lista_t* lista, elem x);

/*  Insere o elemento 'x' na lista          */
void insere(Lista_t* lista, elem x);

/*  Exibe todos os elementos da lista       */
void imprime(Lista_t* lista);

/*  Inverte todas as posicoes da lista (comeca de tras pra frente) */
Lista_t* inverte(Lista_t* lista);
