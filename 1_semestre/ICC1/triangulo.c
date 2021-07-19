#include <stdio.h>

int main () {

    int n = 0, j = 1, impar[25];
    char c;

    //achando os primeiros 25 impares
    for (int i = 1, j = 0; i < 50; i = i + 2, j++)
    {
        impar[j] = i;
        //printf (" %i \n", impar[j]);
    }

    scanf (" %i", &n);
    scanf (" %c", &c);

    //variavel pra determinar os espacos antes de cada linha
    int ini = n - 1;

    if (n > 25 || n <= 0){
        printf ("Altura invalida\n");
    }else {

        for (int i = 0; i < n; i++)
        {
            //gerando espaco antes de cada linha
            while (j <= ini){
                printf (" ");
                j++;
            }

            ini = ini - 1;
            j = 1;

            for (int k = 1; k <= impar[i]; k++){
                printf ("%c", c);
            }
           
            printf ("\n");
        }
    
    } 
    return 0;
}