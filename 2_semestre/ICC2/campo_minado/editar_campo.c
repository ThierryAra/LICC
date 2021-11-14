#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"editar_campo.h"

struct jogo {
    char** campo;
    int** dicas;
    int altura, largura;
};

JOGO* criar_campo(){
    JOGO* jogo;

    jogo = malloc(sizeof(JOGO));

    jogo->campo = NULL;
    jogo->dicas = NULL;  
    jogo->altura = 0;
    jogo->largura = 0;
}

void receber_jogo(JOGO* jogo, char* nome_jogo){
    FILE* arquivo = fopen(nome_jogo, "r");

    if (arquivo == NULL)
        exit(1);
    
    char caractere_lido;
    int altura = -1, largura = 0, evitar_realloc = 0;
    
    while(!feof(arquivo)) {
        fscanf(arquivo, "%c", &caractere_lido);

        // IF para verificar o ultimo \n, que nao atribui conteudo para o campo minado
        if (caractere_lido != '\n'){
            altura++;
            jogo->campo = realloc(jogo->campo, (altura + 1) * sizeof(char **));
            jogo->campo[altura] = NULL;
        }

        while(caractere_lido != '\n' && !feof(arquivo)) {
            if(jogo->largura == 0) 
                jogo->campo[altura] = realloc(jogo->campo[altura], (largura + 1) * sizeof(char *));
            else if (evitar_realloc == 0){ //evita varios realloc's
                jogo->campo[altura] = malloc(jogo->largura * sizeof(char *));
                evitar_realloc = 1;
            }
            jogo->campo[altura][largura] = caractere_lido;
            largura++;

            fscanf(arquivo, "%c", &caractere_lido);
        }
        
        if(jogo->largura == 0) jogo->largura = largura; 
        largura = 0;
        evitar_realloc = 0;
    }
    jogo->altura = altura + 1;

    fclose(arquivo);
}

void gerar_campo_dicas (JOGO* jogo){
    jogo->dicas = malloc (jogo->altura * sizeof(int**));
    for(int altura = 0; altura < jogo->altura; altura++)
        (jogo->dicas)[altura] = calloc (jogo->largura, sizeof(int*));

    for(int altura = 0; altura < jogo->altura; altura++){
        for(int largura = 0; largura < jogo->largura; largura++){
            if((jogo->campo)[altura][largura] == '*')
                adicionar_dicas(jogo, altura, largura);
        }
    }
}

void adicionar_dicas(JOGO* jogo, int altura, int largura){
    if(largura > 0){
        VIZINHO((jogo->campo)[altura][largura - 1], (jogo->dicas)[altura][largura - 1]);
        if(altura > 0)
            VIZINHO((jogo->campo)[altura - 1][largura - 1], (jogo->dicas)[altura - 1][largura - 1]);
        if(altura < jogo->altura - 1)
            VIZINHO((jogo->campo)[altura + 1][largura - 1], (jogo->dicas)[altura + 1][largura - 1]);
    } 

    if(largura < (jogo->largura) - 1){
        VIZINHO((jogo->campo)[altura][largura + 1], (jogo->dicas)[altura][largura + 1]);
        if((altura > 0))
            VIZINHO((jogo->campo)[altura - 1][largura + 1], (jogo->dicas)[altura - 1][largura + 1]); 
        if(altura < (jogo->altura) - 1)
            VIZINHO((jogo->campo)[altura + 1][largura + 1], (jogo->dicas)[altura + 1][largura + 1]);
    }

    if (altura > 0)
        VIZINHO((jogo->campo)[altura - 1][largura], (jogo->dicas)[altura - 1][largura]);
    if (altura < (jogo->altura) - 1)
        VIZINHO((jogo->campo)[altura + 1][largura], (jogo->dicas)[altura + 1][largura]);
}

void exibir_dicas (JOGO* jogo){
    for(int linha = 0; linha < jogo->altura; linha++){
        for(int coluna = 0; coluna < jogo->largura; coluna++){
            if((jogo->campo)[linha][coluna] == '*')
                printf("%c", (jogo->campo)[linha][coluna]);
            else if ((jogo->dicas)[linha][coluna] == 0)
                printf("%c", '.');
            else
                printf("%d", (jogo->dicas)[linha][coluna]);
        }
        printf("\n");
    }
}

void imprimir_campo (JOGO* jogo){
    for(int linha = 0; linha < jogo->altura; linha++){
        for(int coluna = 0; coluna < jogo->largura; coluna++)
                printf("%c", (jogo->campo)[linha][coluna]);
        printf("\n");
    }
}

void acao(JOGO* jogo, int coord_y, int coord_x){
    
    if((jogo->campo)[coord_y][coord_x] == '*'){
        exibir_dicas(jogo);
    } else if((jogo->dicas)[coord_y][coord_x] != 0){
        for(int i = 0; i < jogo->altura; i++){
            for(int j = 0; j < jogo->largura; j++){
                if (i == coord_y && j == coord_x)
                    printf("%d", (jogo->dicas)[i][j]);
                else 
                    printf ("%c", 'X');
            }
            printf ("\n");
        }   
    } else {
        int** campo_recursivo;
        campo_recursivo = malloc (jogo->altura * sizeof(char**));
        for(int altura = 0; altura < jogo->altura; altura++)
            (campo_recursivo)[altura] = calloc (jogo->largura, sizeof(char*));
    
        espaco_vazio(jogo, coord_y, coord_x, &campo_recursivo);
        exibir_campo_recursivo(jogo, &campo_recursivo);
        for(int i = 0; i < jogo->altura; i++) 
            free(campo_recursivo[i]);
        free(campo_recursivo);
    }
}

void espaco_vazio(JOGO* jogo, int coord_y, int coord_x, int*** campo_recursivo){
    //garante que o espaco sem dicas não vai ser modificado quando entrar em recursao
    (jogo->dicas)[coord_y][coord_x] = -1;
    //1 == espaco vazio no campo_recursivo
    (*campo_recursivo)[coord_y][coord_x] = 1;
   
    if(coord_x > 0){
        if ((jogo->dicas)[coord_y][coord_x - 1] == 0) //0 == espaco sem dicas
            espaco_vazio(jogo, coord_y, coord_x - 1, campo_recursivo);
        else if ((jogo->dicas)[coord_y][coord_x - 1] != -1) //-1 == espaco ja verificado nas dicas
            (*campo_recursivo)[coord_y][coord_x - 1] = -2; //-2 == limite 
    }
        
    if(coord_x < (jogo->largura) - 1){
        if ((jogo->dicas)[coord_y][coord_x + 1] == 0)
            espaco_vazio(jogo, coord_y, coord_x + 1, campo_recursivo);
        else if ((jogo->dicas)[coord_y][coord_x + 1] != -1) 
            (*campo_recursivo)[coord_y][coord_x + 1] = -2;
    }

    if ((coord_y > 0)){
        if ((jogo->dicas)[coord_y - 1][coord_x] == 0)
            espaco_vazio(jogo, coord_y - 1, coord_x, campo_recursivo);
        else if ((jogo->dicas)[coord_y - 1][coord_x]!= -1) 
            (*campo_recursivo)[coord_y - 1][coord_x] = -2;
        
        if(coord_x > 0){
            if ((jogo->dicas)[coord_y - 1][coord_x - 1] == 0)
                espaco_vazio(jogo, coord_y - 1, coord_x - 1, campo_recursivo);
            else if ((jogo->dicas)[coord_y - 1][coord_x - 1] != -1) 
                (*campo_recursivo)[coord_y - 1][coord_x - 1] = -2;
        }
        if ((coord_x < (jogo->largura) - 1)){
            if ((jogo->dicas)[coord_y - 1][coord_x + 1] == 0)
                espaco_vazio(jogo, coord_y - 1, coord_x + 1, campo_recursivo);
            else if ((jogo->dicas)[coord_y - 1][coord_x + 1] != -1) 
                (*campo_recursivo)[coord_y - 1][coord_x + 1] = -2;    
        }
    }


    if (coord_y < (jogo->altura) - 1){
        if ((jogo->dicas)[coord_y + 1][coord_x] == 0)
            espaco_vazio(jogo, coord_y + 1, coord_x, campo_recursivo);
        else if ((jogo->dicas)[coord_y + 1][coord_x] != -1) 
            (*campo_recursivo)[coord_y + 1][coord_x] = -2;

        if (coord_x > 0){
            if ((jogo->dicas)[coord_y + 1][coord_x - 1] == 0)
                espaco_vazio(jogo, coord_y + 1, coord_x - 1, campo_recursivo);
            else if ((jogo->dicas)[coord_y + 1][coord_x - 1] != -1) 
                (*campo_recursivo)[coord_y + 1][coord_x - 1] = -2;
        }
        
        if (coord_x < (jogo->largura) - 1){
            if ((jogo->dicas)[coord_y + 1][coord_x + 1] == 0)
                espaco_vazio(jogo, coord_y + 1, coord_x + 1, campo_recursivo);
            else if ((jogo->dicas)[coord_y + 1][coord_x + 1] != -1) 
                (*campo_recursivo)[coord_y + 1][coord_x + 1] = -2; 
        }   
    }
}

void exibir_campo_recursivo(JOGO* jogo, int*** campo_recursivo){
    for(int altura = 0; altura < jogo->altura; altura++){
        for(int largura = 0; largura < jogo->largura; largura++){
            switch ((*campo_recursivo)[altura][largura]) {
                case 0:
                    printf ("%c", 'X');
                    break;
                case 1:
                    printf ("%c", '.');
                    break;
                case -2:
                    printf ("%d", (jogo->dicas)[altura][largura]);
                    break;
            }
        }
        printf ("\n");
    }
}

void excluir_tabuleiro(JOGO* jogo){
    for(int i = 0; i < jogo->altura; i++) free((jogo->campo)[i]);
    free(jogo->campo);
    
    if (jogo->dicas != NULL){
        for(int i = 0; i < jogo->altura; i++) free((jogo->dicas)[i]);
        free(jogo->dicas);
    }

    free(jogo);
    jogo = NULL;
}