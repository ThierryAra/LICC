#include<stdio.h>
#include<stdlib.h>
#include"editar_pilha.h"

typedef struct funcionario{
    char nome[20];
    int idade;
} FUNCIONARIO;


int main(){

    PILHA* pilha;

    pilha = criar_pilha(sizeof(FUNCIONARIO));

    char c;
    FUNCIONARIO funcionario;
    
    c = getchar();
    while (c != 'a') {
        ungetc(c, stdin);
        scanf("%s", funcionario.nome);
        scanf("%i", &funcionario.idade);
        getchar();

        int add = push(pilha, &funcionario);
        if (add == -1) printf ("ERRO NA ADICAO DO FUNCIONARIO\n\n");
        c = getchar();
    }

    top(pilha, &funcionario);
    printf("FUNCIONARIO DO TOPO:\n");
    printf("    NOME.: %s\n", funcionario.nome);
    printf("    IDADE: %i\n", funcionario.idade);

    while (vazia(pilha) == 0) {
        int exclusao = pop(pilha, &funcionario);
        if (exclusao == 1){
            printf("FUNCIONARIO EXCLUIDO: \n");
            printf("    NOME.: %s\n", funcionario.nome);
            printf("    IDADE: %i\n", funcionario.idade);
        } else {
            printf ("\n\nERRO NA EXCLUSAO\n\n");    
            destruir(pilha);
            return 1;
        }
    }

    destruir(pilha);
    return 0;
}















char* receber_string () {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}
