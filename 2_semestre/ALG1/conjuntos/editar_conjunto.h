#include <stdbool.h>

typedef short int sint;

#ifndef N
#define N 100
#endif

//Atribui valores aleatorios a um conjunto, retornando-o
sint *criar_conjunto ();

//Remove determinado numero do conjunto 
void remover_numero (sint *conjunto, int numero);

//Verifica se determinado numero pertence ao conunto, se sim retorna TRUE
bool verificar_membro (sint *conjunto, int numero);

//Insere determinado numero ao conjunto
void inserir_membro (sint *conjunto, int numero);

//Libera o espaco de memoria que armarzenava um conjunto
void eliminar_conjunto (sint *conjunto);

//Exibe todos os valores do conjunto
void imprimir (sint *conjunto);