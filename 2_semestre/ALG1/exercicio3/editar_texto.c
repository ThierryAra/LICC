#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_texto.h"

struct dados{
    char* texto;
    int tam_texto;
    char* texto_corrigido;
    char* corrigir;
    char* corrigido;
};


DADOS* criar_dados(){
    DADOS* dados;

    dados = malloc(sizeof(DADOS));
    dados->texto = NULL;
    dados->texto_corrigido = NULL;
    dados->tam_texto = 0;

    return dados;
}

int receber_texto(DADOS* dados){
    dados->texto = malloc(TAM_TEXTO * sizeof(char));
    
    char caractere = getchar();
    int c = 0;
    while(caractere != '\n' && caractere != EOF){
        if(c >= 100) //caso o texto possua + de 100 caracteres, aumenta-se o tamanho  de 'texto'
            dados->texto = realloc(dados->texto, (c + 1) * sizeof(char));

        (dados->texto)[c] = caractere;
        caractere = getchar();
        c++;
    }

    //Caso encontre EOF nao ha mais dados para serem recebidos
    if(caractere == EOF){
        free(dados->texto);
        return 0;
    }

    dados->tam_texto = c;
    
    //Adiciona \0 ao final de 'texto'
    if(c < TAM_TEXTO)
        (dados->texto)[c] = '\0';

    int tamanho_texto = strlen(dados->texto);

    //Recebe a palavra a ser corrigida, assim como sua correcao
    dados->corrigir = receber_palavra();
    dados->corrigido  = receber_palavra();

    return 1;
}

char* receber_palavra(){
    char* texto;
    texto = malloc(TAM_CORRIGIR * sizeof(char));
    
    char caractere = getchar();
    int c = 0;
    while(caractere != '\n' && caractere != EOF){
        if(c >= 20) //evita varios realloc's constantes
            texto = realloc(texto, (c + 1) * sizeof(char));

        (texto)[c] = caractere;
        caractere = getchar();
        c++;
    }

    //Retorna o EOF para entrar na condicao de parada de 'receber_texto'
    if(caractere == EOF)
        ungetc(caractere, stdin);

    if(c < TAM_TEXTO)
        (texto)[c] = '\0';
    
    return texto;
}

void corrigir_texto(DADOS* dados){
    int tam_corrigir  = strlen(dados->corrigir);
    int tam_corrigido = strlen(dados->corrigido);
    dados->texto_corrigido = malloc(TAM_TEXTO * sizeof(char));

    int indice = 0;
    int trecho_diferente = 0;

    for(int i = 0; i < (dados->tam_texto); i++, indice++){
        //Encontra a primeira letra da palavra a ser corrigida no 'texto'
        if((dados->texto)[i]  == dados->corrigir[0]){
            //verifico se o trecho eh realmente o que deve ser substituido
            for (int j = 0, k = i; j < tam_corrigir; j++, k++){
                if(((dados->texto)[k]  != dados->corrigir[j])){
                    //Caso nao seja, o indice de texto 'i' volta a sua posicao original
                    i -= j - 1;
                    trecho_diferente = 1;
                    break;
                }
            }

            //Se o trecho for realmente igual, 'texto_corrigido' recebe o trecho correto
            if(!trecho_diferente){
                int j;
                for (j = 0; j < tam_corrigido; j++, indice++, i++)
                    dados->texto_corrigido[indice] = (dados->corrigido)[j];
            }

            //Faz a correcao do indice de 'texto', por conta da variacao de letras
            //entre a palavra a ser corrigida e sua correcao
            if(tam_corrigir > tam_corrigido) 
                i = (i + (tam_corrigir - tam_corrigido));
            else 
                i = i - (tam_corrigido - tam_corrigir);
        }


        dados->texto_corrigido[indice] = (dados->texto)[i];
        trecho_diferente = 0;
    }
    dados->texto_corrigido[indice] = '\0';
}

void exibir_texto_corrigido(DADOS* dados){
    int tam_texto = strlen(dados->texto_corrigido);
    for (int i = 0; i < TAM_TEXTO && i < tam_texto; i++)
        printf("%c", (dados->texto_corrigido)[i]);

    printf("\n");
}

void excluir_textos(DADOS* dados){
    if(dados == NULL)
        return;

    free(dados->texto);
    free(dados->texto_corrigido);
    free(dados->corrigido);
    free(dados->corrigir);
}