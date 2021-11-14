/*  Exercicio Sustituir Strings
    Thierry de Souza Araujo - 12681094
    USP - Sao Carlos - ICMC
    Algoritmos e Estruturas de Dados (SCC0202) */

#include<stdio.h>
#include<stdlib.h>
#include"editar_texto.h"

int main(){

    DADOS* dado;

    dado = criar_dados();

    int fim = 0;

    while(receber_texto(dado)){
        corrigir_texto(dado);
        exibir_texto_corrigido(dado);
        excluir_textos(dado);
    }

    free(dado);
    return 0;
}