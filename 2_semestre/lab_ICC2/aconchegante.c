/*  Exercicio Ordenacao Aconchegante
    Thierry de Souza Araujo - 12681094
    USP - ICMC - São Carlos
    Bacharelado em Ciencias da Computacao
    Laboratorio de Introducao a Ciencia da Computacao II (SCC0220) */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct concha{
    float diametro;
    char* cor;
    char* textura;
}CONCHAS;

/*  Recebe e retorna uma string da entrada padrao */
char* receber_string();

/*  Ordena as conchas, de forma crescente, de acordo com seu diametro
    PARAMETROS:
        conchas       : Vetor que contem as conchas desordenadas
        qtd_conhcas   : Quantidade de conchas no vetor (tamanho do vetor) 
        qtd_sub_listas: A cada recursao vale (qtd_conchas/(2*n)), sendo n as vezes que a recursao
                        foi acionada, comecando em 1                                             */
void ordenar(CONCHAS* conchas, int qtd_conchas, int qtd_sub_listas);

/*  Exibe todos as conchas, no formato %diamentro% %cor% %textura% */
void print(CONCHAS* conchas, int qtd_conchas);

/*  Libera o espaco armazenado para o ponteiro conchas e suas dependencias */
void liberar(CONCHAS* conchas, int qtd_conchas);

int main(int argc, char const *argv[]){
    CONCHAS* conchas;

    int qtd_conchas = 0;
    scanf("%d", &qtd_conchas);
    conchas = (CONCHAS*)malloc(qtd_conchas * sizeof(CONCHAS));

    int i = 0;
    //Recebendo os dados
    while (i < qtd_conchas){
        scanf("%f", &(conchas[i]).diametro);
        getchar();
        (conchas[i]).cor     = receber_string();
        (conchas[i]).textura = receber_string();
        i++;
    }
    
    ordenar(conchas, qtd_conchas, qtd_conchas/2);

    print(conchas, qtd_conchas);

    liberar(conchas, qtd_conchas);

    return 0;
}

void ordenar(CONCHAS* conchas, int qtd_conchas, int qtd_sub_listas){
    assert(conchas != NULL);
    if(qtd_sub_listas == 0)
        return;

    // k vai ser igual a todos os possiveis resto da divisao de i por qtd_sub_listas
    // ou seja, de 0 ate qtd_sub_listas
    int k = 0, i = k + qtd_sub_listas;
    
    //insertion sort para cada sub_lista 
    //SL = {X c C | (i mod qtd_sub_listas) == k} e C = {Y c conchas[i].diametro, 0 <= i < qtd_conchas}
    while (k < qtd_sub_listas){
        CONCHAS elem;
        elem = conchas[i];
        int indice = i - qtd_sub_listas;
        
        while(indice >= 0 && elem.diametro < (conchas[indice]).diametro){ 
            (conchas[indice + qtd_sub_listas]) = (conchas[indice]);
            indice -= qtd_sub_listas;
        }
            
        (conchas[indice + qtd_sub_listas]) = elem;

        i += qtd_sub_listas;
        
        //Caso i seja maior que qtd_conchas, quer dizer que a sub_lista ja foi toda verificada
        //Assim, k aumenta uma unidade para verificar a proxima sub_lista
        if(i >= qtd_conchas){
            k++;
            i = k;
        }
    }
    
    ordenar(conchas, qtd_conchas, qtd_sub_listas/2);
}

void print(CONCHAS* conchas, int qtd_conchas){
    int i = 0;
    while (i < qtd_conchas){
        printf("%.3f %s %s\n", conchas[i].diametro, conchas[i].cor, conchas[i].textura);
        i++;
    }
}

char* receber_string(){
    char entrada;
    char *string = NULL;
    int i = 1;

    entrada = getchar();
    while (entrada != '\n' && entrada != ' ' && entrada != EOF) {
        string = (char*)realloc(string, i * sizeof(char *));
        assert(string != NULL);
        
        *(string + (i - 1)) = entrada;
        i++;
        entrada = getchar();
    }

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}

void liberar(CONCHAS* conchas, int qtd_conchas){
    assert(conchas != NULL);
    
    for (int i = 0; i < qtd_conchas; i++){
        free(conchas[i].cor);
        free(conchas[i].textura);
    }
    
    free(conchas);
}
