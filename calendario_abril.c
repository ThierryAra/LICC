#include<stdio.h>

int main () {

    int data = 0, dias_30[30], atual = 0;

    scanf ("%d", &data);

    for (int i = 1; i <= 30; i++)
    {
        dias_30[i - 1] = i;
        
    }


    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            //espacos em branco ate quinta da primeira semana e depois do dia 30
            if ((i == 0 && j <= 3) || (i == 4 && j > 5)) {
                printf ("    ");
            //impressao da data com ( )
            } else if (data == dias_30[atual]) {
                if (dias_30[atual] < 10){ 
                    printf ("( %d)", data);
                    atual++;
                } else {
                    printf ("(%d)", data);
                    atual++;
                }
            //impressao dos dias normais
            } else {
                if (dias_30[atual] < 10){ 
                    printf ("  %d ", dias_30[atual]);
                    atual++;
                } else {
                    printf (" %d ", dias_30[atual]);
                    atual++;
                }
            }
        }
        printf ("\n");
    }
    
    return 0;
}