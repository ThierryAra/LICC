// Tamanho maximo para a fila, levando em conta o numero de entradas (0 < n <= 100)
#define TAMFILA 100

typedef struct paciente {
    char* nome;
    int idade;
    int agravante;
    int prioridade;
} PACIENTE;

typedef struct fila FILA;

/* Aloca espaco para uma fila */
FILA* criar();

/* Verifica se a fila esta vazia (retorna 1), ou nao (retorna 0) ou -1(erro de memoria) */
int is_empty(FILA* fila);

/* Verifica se a fila esta cheia (retorna 1), ou nao (retorna 0) ou -1(erro de memoria) */
int is_full(FILA* fila);

/* Insere o paciente na fila em sua posicao ideal 
    Ordem das prioridades
        idoso + agravante   = 1
        jovem + agravante   = 2
        idoso (+= 60 anos)  = 3
        jovem sem agravante = 4
*/
int insert(FILA* fila, PACIENTE* paciente);

/* Remove o primeiro paciente da fila e tranfere para a variavel paciente */
int remover(FILA* fila, PACIENTE* paciente);

/* Exclui a fila e limpa a memoria */
void excluir(FILA* fila);

/* Aloca e retorna um espaco na memoria para um paciente */
PACIENTE* criar_paciente();