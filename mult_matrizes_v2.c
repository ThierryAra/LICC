#include<stdio.h>
#include <stdlib.h>

int main () {

    int semente, LA, CA, LB, CB;

    scanf ("%d %d", &LA, &CA);
    scanf ("%d %d", &LB, &CB);

    if (LA <= 0 || LB <= 0 || CA <= 0 || CB <= 0 || CA != LB){
        printf ("Valores invalidos para a multiplicacao.");
        return 0;
    }

    int matA[LA][CA], matB[LB][CB];

    scanf ("%d", &semente);

    srand(semente);

    //valores da matA
    for (int i = 0; i < LA; i++)
    {
        for (int j = 0; j < CA; j++)
        {
            matA[i][j] = rand()%50 - 25;
            //matA[i][j] = i+j;
        }
    }

    /*for (int i = 0; i < LA; i++)
    {
        for (int j = 0; j < CA; j++)
        {
            printf ("%i\t", matA[i][j]);
        }
        printf ("\n");
    }printf ("\n");*/

     //valores da matB
    for (int i = 0; i < LB; i++)
    {
        for (int j = 0; j < CB; j++)
        {
            matB[i][j] = rand()%50 - 25;
            //matB[i][j] = i-j;
        }
    }

    /*for (int i = 0; i < LB; i++)
    {
        for (int j = 0; j < CB; j++)
        {
            printf ("%i\t", matB[i][j]);
        }
        printf ("\n");
    }printf ("\n");*/

    int matC[LA][CB], soma = 0;
    
    //linha matC
    for (int lin = 0; lin < LA; lin++)
    {
        //coluna matC
        for (int col = 0; col < CB; col++)
        {
            //somador linhaA x colunaB
            for (int cont = 0; cont < CA; cont++)
            {
                soma = soma + (matA[lin][cont] * matB[cont][col]);
            }
            matC[lin][col] = soma;
            soma = 0;
        }
    }
    
    //printar valores de matC
    for (int i = 0; i < LA; i++)
    {
        printf ("Linha %d: ", i);
        for (int j = 0; j < CB; j++)
        {
            printf ("%i ", matC[i][j]);
        }
        printf ("\n");
    }

    return 0;
}