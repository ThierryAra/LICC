#define QTD_ABERTURA 200
#include"editar_pilha.h"

/*  Analisa o texto de entrada, verificando se os marcadores estao na ordem correta
    { ( } ) -> incorreto
    { ( ) } -> correto
    (Retorna o EOF para a entrada padrao, quando encontrado)
    RETORNO:
        Retorna um int que sera 1, para correto, ou 0 para incorreto          */
int analisar_texto(PILHA* pilha);