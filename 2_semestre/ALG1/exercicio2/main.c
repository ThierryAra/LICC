/*  Exercicio Crivo de Erastostenes
    Thierry de Souza Araujo - 12681094
    USP - Sao Carlos - ICMC
    Algoritmos e Estruturas de Dados (SCC0202) */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"editar_primos.h"

int main(){

    tipo_dado *primos, *vetor = NULL;

    int n = 0;
    scanf("%d", &n);

    vetor = criar_vetor(LIMITE);
    
    receber_numeros(&vetor, LIMITE);
    
    primos = crivo_de_erastostenes(vetor, LIMITE);

    int posicao = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &posicao);

        printf("%d ", primos[posicao - 1]);
    }
    printf("\n");

    excluir_vetor(vetor, primos);
    
    return 0;
}