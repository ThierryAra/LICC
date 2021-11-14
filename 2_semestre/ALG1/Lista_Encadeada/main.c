#include<stdio.h>
//double free na primeira variavel de lista
#include<stdlib.h>
#include"lista_e.h"

int main(){
    Lista_t *lista, *lista_inversa;

    lista = criar();

    insere(lista, 5);
    insere(lista, 6);
    insere(lista, 7);
    insere(lista, 3);
    imprime(lista);

    lista_inversa = inverte(lista);

    imprime(lista_inversa);

    free(lista);
    libera(lista_inversa);
    return 0;
}
