#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "editar_conjunto.h"

sint *criar_conjunto(){
    sint *conjunto = malloc (N * sizeof(sint));

    for (int i = 0; i < N; i++)
        conjunto[i] = rand() % 2;   

    return conjunto; 
}

void remover_numero(sint *conjunto, int numero){
    if(conjunto == NULL)
        return;

    if(conjunto[numero] == 1)
        conjunto[numero] = 0;
}

bool verificar_membro(sint *conjunto, int numero){
    if(conjunto == NULL)
        return false;

    if(conjunto[numero] == 1)
        return true;
    else 
        return false;
}

void inserir_membro(sint *conjunto, int numero){
    if(conjunto == NULL)
        return;

    if(conjunto[numero] == 0)
        conjunto[numero] = 1;
}

void eliminar_conjunto(sint *conjunto){
    free(conjunto);
}

void imprimir(sint *conjunto){
    if(conjunto == NULL)
        return;

    printf ("\n");
    for(int i = 0; i < N; i++)
        if (conjunto[i] == 1)
            printf("| %2d |", i); 
    printf ("\n");
}