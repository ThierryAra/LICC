//todos os antigos foram por erro no formato de saida (até descobrir q ja tava pronto na descricao)
#include<stdio.h>
#include<string.h>

int main () {

    int linhas = 0, palavras = 0, caract = 0, repeticao = 1;
    char texto;

    texto = getchar();
    while (texto != EOF)
    {
        caract++;

        //trata das repeticoes de '\n' ou ' '
        if (texto == ' ' || texto == '\n' || texto == '\t' || texto == '\r')
            repeticao = 1;
        //caso haja um ' ' ou '\n' e depois outro tipo de caracter, quer dizer q teve uma palavra antes
        else if (repeticao == 1){
            repeticao = 0;
            palavras++;
        }

        if (texto == '\n')
            linhas++;


        texto = getchar();
    } 

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", linhas, palavras, caract);

  return 0;
}
