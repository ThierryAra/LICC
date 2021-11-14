/*  Exercicio Rotacao da Lista
    Thierry de Souza Araujo - 12681094
    USP - Sao Carlos - ICMC
    Bacharelado em Ciencias da Computacao
    Algoritmos e Estruturas de Dados (SCC0202) */
#include<stdio.h>
#include"editar_lista.h"

int main(){
    Lista_t *lista;


    int qtd_testes;
    scanf("%d", &qtd_testes);

    while (qtd_testes > 0){
        int tam_lista;
        scanf("%d", &tam_lista);
        
        lista = criar(tam_lista);

        //Quantidade de inversoes na lista
        int inversor;
        scanf("%d", &inversor);

        //Inserindo os valores na lista
        while (tam_lista > 0){
            int dado;
            scanf("%d", &dado);

            insere(lista, dado);
            tam_lista--;
        }
        
        while (inversor > 0){
            inverte(lista);
            inversor--;
        }
        

        imprime(lista);
        libera(lista);
        qtd_testes--;
    }
    
    return 0;
}
