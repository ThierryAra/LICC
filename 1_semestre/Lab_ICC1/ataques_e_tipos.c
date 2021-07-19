#include<stdio.h>
#include<stdlib.h>

int main () {

    int dimensao = 0, i = 0, j = 0, i_melhor_atq = 0, inimigo = 0;
    float melhor_atq = 0.0;

    scanf ("%i", &dimensao);

    //valores da tabela
    float **tabela = malloc (dimensao * sizeof(float *));

    for (i = 0; i < dimensao; i++)
    {
        tabela[i] = calloc (dimensao, sizeof(float *));
        for (j = 0; j < dimensao; j++)
        {
            scanf ("%f", (tabela[i] + j));
        }     
    }

    //ataques a serem comparados 
    int qtd_ataques = 1;
    int *ataques = malloc (qtd_ataques * sizeof(int *));
    while (1)
    {
        //armazena (dano_ataque, atacante) -> (j, j + 1)
        scanf ("%i", (ataques + (qtd_ataques - 1)));
        if (ataques[qtd_ataques - 1] != -1) {
            qtd_ataques += 1;
            ataques = realloc (ataques, qtd_ataques * sizeof(int *));
            scanf ("%i", (ataques + (qtd_ataques - 1)));
        }
        else
            break;

        qtd_ataques += 1;
        ataques = realloc (ataques, qtd_ataques * sizeof(int *));
    }
    
    scanf ("%i", &inimigo);

    //comparando o dano de cada ataque
    j = 0;
    while (j <= (qtd_ataques - 3))
    {
        float atq_atual = (ataques[j] * tabela[ataques[j+1]][inimigo]);
        if ( atq_atual > melhor_atq ){
            melhor_atq = atq_atual;
            i_melhor_atq = ataques[j+1];
        }
        j += 2;
    }
    
    printf ("O melhor ataque possui indice %i e dano %.2f\n", i_melhor_atq, melhor_atq);

    for (j = 0; j < dimensao; j++)
        free (tabela[j]);
    free(tabela);
    free(ataques);
    
    return 0;
}