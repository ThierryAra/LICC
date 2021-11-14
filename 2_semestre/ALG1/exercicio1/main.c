/*  Exercicio Frases
    Thierry de Souza Araujo - 12681094
    USP Sao Carlos - ICMC
    Algoritmo e Estrutuda de Dados I (SCC0202)    */
    
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_texto.h"

int main(){

    dados_t* dados;
    int k;
    

    dados = criar_dado();
    while(receber_texto(&dados, &k)){
        contar_repeticao(&dados);

        if(ordenar_vetor_qtd(dados)){
            char fim_arquivo = getchar();
            
            if(ordenar_vetor_letra(dados)){
                ordenar_vetor_letra(dados);
                imprimir_resultado(dados, k);
                
                if(fim_arquivo != EOF)
                    printf("\n");
                ungetc(fim_arquivo, stdin);
            }
        }
        
        excluir_dados(dados);
        dados = criar_dado();
    }

    return 0;
}