#include<stdio.h>
#include<stdlib.h>

#define tipo_dado int
#define LIMITE 1000

tipo_dado* criar_vetor(int n){
    tipo_dado* vetor;

    vetor = malloc(n * sizeof(tipo_dado));

    return vetor;
}

void receber_numeros(tipo_dado* vetor, int n){
    for (int i = 2, k = 0; k < LIMITE; i++, k++)
        vetor[k] = i;
}

void exibir_numeros(tipo_dado* vetor, int n){
    for (int i = 0; i < n; i++)
        printf("%d  ", vetor[i]);
}

void crivo_de_eratostenes(tipo_dado* vetor, int n, tipo_dado** primos){
    if(vetor == NULL)
        return;

    int adicionado = 1, indice = 0;

    (*primos) = NULL;//malloc(sizeof(tipo_dado));
    //(*primos)[0] = 2;

    for (int i = 0; i < LIMITE; i++){
        //printf("%d\n",vetor[i]);
        if(vetor[i] == 0)
            while (vetor[i] == 0) i++;
        
        int primo = vetor[i];

        (*primos) = realloc((*primos), sizeof(tipo_dado) * (indice + 1));
        (*primos)[indice] = primo;
        indice++;


        for (int j = i + 1; j < LIMITE; j++){
            if(primo == 0)
                break;
            //printf("%d / %d = %d\n", vetor[j], (*primos)[indice - 1], (vetor[j] % (*primos)[indice - 1]));
            if(vetor[j] != 0 && ((vetor[j] % primo) == 0)){
                vetor[j] = 0;
            }
        }
        adicionado = 0;
    }  

    printf("\n%d\n\n", indice);
    exibir_numeros(*primos, indice);
}

void excluir_vetor(tipo_dado* vetor, tipo_dado* primos){
    if(vetor == NULL)
        return;

    free(vetor);
    free(primos);
}

int main(){

    tipo_dado *primos, *vetor;

    int n = 3;
    //scanf("%d", &n);

    vetor = criar_vetor(LIMITE);
    receber_numeros(vetor, LIMITE);
    //exibir_numeros(vetor, LIMITE);
    crivo_de_eratostenes(vetor, LIMITE, &primos);

    int posicao = 0;
    /* for (int i = 0; i < n; i++){
        scanf("%d", &posicao);

        printf("%d ", primos[posicao]);
    } */

    excluir_vetor(vetor, primos);
    
    return 0;
}