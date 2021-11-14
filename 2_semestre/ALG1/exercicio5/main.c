/*  Exercicio Sequencia Balanceada
    Thierry de Souza Araujo - 12681094
    USP - Sao Carlos - ICMC
    Bacharelado em Ciencias da Computacao
    Algoritmos e Estruturas de Dados (SCC0202) */
#include<stdio.h>
#include"editar_texto.h"
#include"editar_pilha.h"

int main(){

    PILHA* pilha_t;


    char caractere = getchar();
    while(caractere != EOF){
        ungetc(caractere, stdin);

        pilha_t = criar_pilha();
        
        if(analisar_texto(pilha_t))
            printf("BALANCEADO\n");
        else
            printf("NÃO BALANCEADO\n");
    
        destruir(pilha_t);

        caractere = getchar();
    }

    return 0;
}