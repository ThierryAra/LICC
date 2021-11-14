#include<stdio.h>
#include<stdlib.h>
#include"editar_primos.h"

tipo_dado* criar_vetor(int n){
    tipo_dado* vetor = NULL;

    vetor = realloc(vetor, n * sizeof(tipo_dado));

    return vetor;
}

void exibir_numeros(tipo_dado* vetor, int n){
    for (int i = 0; i < n; i++)
        printf("%d  ", vetor[i]);
}

void receber_numeros(tipo_dado** vetor, int n){
    for (int i = 2, k = 0; k < LIMITE; i++, k++)
        (*vetor)[k] = (tipo_dado)i;
}

tipo_dado* crivo_de_erastostenes(tipo_dado* vetor, int n){
    tipo_dado* primos = NULL;
    if(vetor == NULL)
        return NULL;

    int indice = 0;

    (primos) = NULL;

    for (int i = 0; i < LIMITE; i++){
        if(vetor[i] == 0)
            while (vetor[i] == 0) i++; //evitar varios numeros que nao devem ser analisados
        
        tipo_dado primo = vetor[i];
   
        (primos) = realloc((primos), sizeof(tipo_dado) * (indice + 1));
        (primos)[indice] = primo;
        indice++;

        for (int j = i + 1; j < LIMITE; j++){
            if(primo == 0)
                break;
            
            //anula todos os multiplos de primo
            if(vetor[j] != 0 && ((vetor[j] % primo) == 0)){
                vetor[j] = 0; //caso seja um multipo do primo, eh anulado
            }
        }
    }  

    return primos;
}

void excluir_vetor(tipo_dado* vetor, tipo_dado* primos){
    if(vetor == NULL)
        return;
    else
        free(vetor);
    
    if(primos == NULL)
        return;
    else
        free(primos);
}