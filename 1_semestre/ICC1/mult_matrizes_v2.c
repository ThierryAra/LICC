#include<stdio.h>
#include <stdlib.h>

int main () {

    int seed, height_A, width_A, height_B, width_B;

    scanf ("%d %d", &height_A, &width_A);
    scanf ("%d %d", &height_B, &width_B);

    if (height_A <= 0 || height_B <= 0 || width_A <= 0 || width_B <= 0 || width_A != height_B){
        printf ("Valores invalidos para a multiplicacao."); //Invalids values for multiplication.
        return 0;
    }

    int matrix_A[height_A][width_A], matrix_B[height_B][width_B];

    scanf ("%d", &seed);

    srand(seed);

    // Matrix_A values
    for (int i = 0; i < height_A; i++)
    {
        for (int j = 0; j < width_A; j++)
        {
            matrix_A[i][j] = rand()%50 - 25;
        }
    }

     // Matrix_B values
    for (int i = 0; i < height_B; i++)
    {
        for (int j = 0; j < width_B; j++)
        {
            matrix_B[i][j] = rand()%50 - 25;
        }
    }

    int matrix_C[height_A][width_B], sum = 0;
    
    //linha matrix_C
    for (int line = 0; line < height_A; line++)
    {
        //coluna matrix_C
        for (int column = 0; column < width_B; column++)
        {
            //somador linhaA x colunaB
            for (int cont = 0; cont < width_A; cont++)
            {
                sum = sum + (matrix_A[line][cont] * matrix_B[cont][column]);
            }
            matrix_C[line][column] = sum;
            sum = 0;
        }
    }
    
    //Print matrix_C values
    for (int i = 0; i < height_A; i++)
    {
        printf ("Linha %d: ", i);
        for (int j = 0; j < width_B; j++)
        {
            printf ("%i ", matrix_C[i][j]);
        }
        printf ("\n");
    }

    return 0;
}

/* 

CASE TEST:

INPUT:
4 8
8 5
144

OUTPUT: 
Linha 0: -145 -172 616 -379 -457 
Linha 1: -750 -642 -186 -756 -429 
Linha 2: 159 635 82 1188 -434 
Linha 3: 50 614 -446 701 216 

 */
