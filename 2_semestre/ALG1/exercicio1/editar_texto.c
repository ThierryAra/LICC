#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_texto.h"

struct dados {
    char** texto;
    int* repeticao;
    int qtd_palavras_texto;
    int qtd_palavras;
};

dados_t* criar_dado(){
    dados_t* dado;

    dado = malloc(sizeof(dados_t));

    dado->texto = NULL;
    dado->repeticao = NULL;
    dado->qtd_palavras = 0;
    dado->qtd_palavras_texto = 0;

    return dado;
}

int receber_texto(dados_t** dado, int* k){
    char entrada = '.';
    int palavra = 1, c = 0;

    //adicionara uma palavra em cada linha da matriz ate encontrar um numero
    while(1){
        (*dado)->texto = (char**)realloc((*dado)->texto, palavra * sizeof(char**));
        
        entrada = getchar();
        if(entrada >= 48 && entrada <= 57) { //verifica se o carater eh um numero
            ungetc(entrada, stdin);
            break;
        } else if (entrada == EOF){ //termina o programa quando for ler a ultima entrada de texto
            excluir_dados((*dado));
            dado = NULL;
            return 0;
        }

        ((*dado)->texto)[palavra - 1] = (char*)malloc(15 * sizeof(char*));
        while(entrada != 32 && entrada != '\n'){
            if(c > 14) //evita realloc's constantes
                ((*dado)->texto)[palavra - 1] = (char*)realloc(((*dado)->texto), (c + 1) * sizeof(char*));

            ((*dado)->texto)[palavra - 1][c] = entrada;
            entrada = getchar();
            c++;
        }

        //adicionando '\0' ao final das palavras
        if(entrada != '\n'){ //retira o \n do fim das palavras que terminam uma linha
            (*dado)->texto[palavra - 1] = realloc((*dado)->texto[palavra - 1], c + 1 * sizeof(char *));
            ((*dado)->texto)[palavra - 1][c] = '\0';  
        } else
            ((*dado)->texto)[palavra - 1][c - 1] = '\0';    

        palavra++;
        c = 0;
    }

    (*dado)->qtd_palavras_texto = palavra - 1;
    scanf("%d\n", k);

    return 1;
}

void contar_repeticao(dados_t** dado){
     if ((*dado) == NULL)
        return;

    int repeat = 0;

    //somando as palavras repetidas
    for(int i = 0; i < (*dado)->qtd_palavras_texto; i++){
        char palavra1[20];
        
        if((*dado)->texto[i] != NULL){
            strcpy(palavra1, (*dado)->texto[i]);
            (*dado)->repeticao = realloc((*dado)->repeticao, (repeat + 2) * sizeof(int));   
            ((*dado)->repeticao)[repeat] = 0; 

            for(int j = 0; j < (*dado)->qtd_palavras_texto; j++){

                if(((*dado)->texto[j] != NULL) && (strcmp(palavra1, (*dado)->texto[j]) == 0)){
                    ((*dado)->repeticao)[repeat]++;
                    //atribui NULL as palavras repetidas, para nao serem contadas novamente
                    if(((*dado)->repeticao)[repeat] >= 2){
                        free((*dado)->texto[j]);
                        (*dado)->texto[j] = NULL;
                    }
                    else {//indica a posicao da palavra na matriz, para facilitar a exibicao depois
                        ((*dado)->repeticao)[repeat + 1] = j;
                    }
                }
            }
            repeat += 2;
        }
    }

    (*dado)->qtd_palavras = repeat / 2;
}

int ordenar_vetor_qtd(dados_t* dado){
    if (dado == NULL)
        return 0;

    if (dado->repeticao == NULL)
        return 0;

    int i = 2;

    //Basicamente um insertion sort 
	while (i < (dado->qtd_palavras * 2)) {		
		int qtd_repeticao = (dado->repeticao)[i];
        int pos = (dado->repeticao)[i + 1];
		int j = i - 2;

		while (j >= 0 && qtd_repeticao > (dado->repeticao)[j]) {
			(dado->repeticao)[j+2] = (dado->repeticao)[j];
            (dado->repeticao)[j+3] = (dado->repeticao)[j + 1];
			j -= 2; 
		}
		
		(dado->repeticao)[j + 2] = qtd_repeticao;
        (dado->repeticao)[j + 3] = pos;

		i += 2;
	}

    return 1;
}

int ordenar_vetor_letra(dados_t* dado){
    if (dado == NULL)
        return 0;

    if (dado->repeticao == NULL)
        return 0;

    int i = 2;
    // Variavel que indicara qual a ordem alfabetica entre 2 palavras 
    int ordem = 0;

	while (i < (dado->qtd_palavras * 2)) {		
		int qtd_repeticao = (dado->repeticao)[i];
        int pos = (dado->repeticao)[i + 1];
		int j = i - 2;

        ordem = strcmp(dado->texto[pos], dado->texto[(dado->repeticao[j+1])]);
        //WHILE se mantem enquanto as palavras possuem o mesmo numero de aparicoes
        //e a palavra[i] eh menor que a palavra[i - 2], invertendo-as
		while (j >= 0 && qtd_repeticao == (dado->repeticao)[j] && ordem < 0) {
            (dado->repeticao)[j+2] = (dado->repeticao)[j];
            (dado->repeticao)[j+3] = (dado->repeticao)[j + 1];
            j -= 2; 
            
            if (j > 0) //garante que nao vou acessar uma posicao invalida de repeticao[]
                ordem = strcmp(dado->texto[pos], dado->texto[(dado->repeticao[j+1])]);
        }
		
		(dado->repeticao)[j + 2] = qtd_repeticao;
        (dado->repeticao)[j + 3] = pos;

		i += 2;
	}

    return 1;
}


void imprimir_resultado(dados_t* dado, int k){
    if (dado == NULL)
        return;

    int contador = 0;

    for(int i = 0; i < dado->qtd_palavras; i++){
        if (contador/2 < k){
            int qtd_repeticao = (dado->repeticao)[contador];
            int posicao = (dado->repeticao)[contador + 1];
            printf("%s %d\n", (dado->texto)[posicao], qtd_repeticao);
            contador += 2; 
        }
    }
}

void excluir_dados(dados_t* dado){
    if(dado == NULL)
        return;

    if(dado->texto != NULL){
        for(int i = 0; i < dado->qtd_palavras_texto; i++)
            if((dado->texto)[i] != NULL) //evita erro nas linhas que foram anuladas na contagem
                free((dado->texto)[i]);
        
        free(dado->texto);
    }

    if(dado->repeticao != NULL){
        free(dado->repeticao);
    }
   
    free(dado);
    dado = NULL;
}