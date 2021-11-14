#include<stdio.h>
#include<stdlib.h>
#include"editar_texto.h"
#include"editar_pilha.h"

int analisar_texto(PILHA* pilha){
    int parar = 1;
    int aspas = 0;
    
    char topo_pilha;

    char caractere = getchar();
    
    if(!push(pilha, caractere))
        return 0;

    if(caractere == '"')
        aspas++;

    caractere = getchar();
    while(caractere != '\n' && caractere != EOF){
        if(!top(pilha, &topo_pilha))
            topo_pilha = 'a';

        switch(caractere){
            case '{':
                if(!push(pilha, '{')){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }               
                break;

            case '(':
                if(!push(pilha, '(')){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }
                break;

            case '[':
                if(!push(pilha, '[')){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }

                break;
            case '"':
                aspas++;
                break;
                
            case ']':
                if(topo_pilha != '[') 
                    parar = 0;

                if(!pop(pilha)){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }
                break;

            case ')':
                if(topo_pilha != '(') 
                    parar = 0;

                if(!pop(pilha)){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }
                break;

            case '}':
                 if(topo_pilha != '{') 
                    parar = 0;

                if(!pop(pilha)){
                    destruir(pilha);
                    exit(EXIT_FAILURE);
                }
                break;

            default:
                break;
        }

        caractere = getchar();
        
        if(parar == 0) //Evita manter a verificacao caso ja encontre erro
            break;
    }
    
    //Limpa a entrada para receber o proximo trecho
    while (caractere != EOF && caractere != '\n') 
        caractere = getchar();
    
    //caso a quantidade de 'aspas' nao seja par, quer dizer que alguma abertura nao foi fechada
    if((aspas % 2) != 0)
        parar = 0;

    if(caractere == EOF) //retorna para a entrada com o intuito de verificar novamente na main e parar
        ungetc(caractere, stdin);

    return parar;
}