/*  Exercicio Fila de Prioridades
    Thierry de Souza Araujo - 12681094
    USP Sao Carlos - ICMC
    Algoritmo e Estrutuda de Dados I (SCC0202)    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_fila.h"

/* Recebe e retorna uma string do teclado */
char* receber_nome();

int main(){

    FILA* fila = NULL;
    PACIENTE* paciente = NULL;
    

    int qtd_acoes;
    scanf("%d\n", &qtd_acoes);
    
    if(qtd_acoes <= 0 || qtd_acoes > 100)
        return 1;
    
    fila = criar();

    char acao[6];
    paciente = criar_paciente();

    for (int i = 0; i < qtd_acoes; i++){
        scanf("%s", acao);
        getchar();
        
        if(strcmp(acao, "ENTRA") == 0){
            paciente->nome = receber_nome();
            scanf("%d", &paciente->idade);
            scanf("%d", &paciente->agravante);
            getchar();
            
            if(!insert(fila, paciente))
                printf("FILA CHEIA\n");
        }  else{
            if(!remover(fila, paciente))
                printf("FILA VAZIA\n");
            else {
                printf("%s %d %d\n", paciente->nome, paciente->idade, paciente->agravante);
            }
        }
    }

    free(paciente);
    excluir(fila);
    return 0;
}

char* receber_nome(){
    char entrada;
    char *string = NULL;
    int i = 1;

    entrada = getchar();
    while (entrada != ' ') {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = entrada;
        i++;
        entrada = getchar();
    }

    //adicionando '\0' ao final da string
    string = (char*)realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}