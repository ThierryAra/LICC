#include<stdio.h>

int main () {

    int vet[25], cores[5] = {0, 0, 0, 0, 0}, maior = 0, i_maior = 0;

    for (int i = 0; i < 25; i++)
    {
        scanf ("%i", &vet[i]);
        if (vet[i] == 0){
            cores[0]++;
        } else if (vet[i] == 1){
            cores[1]++;
        } else if (vet[i] == 2){
            cores[2]++;
        } else if (vet[i] == 3){
            cores[3]++;
        } else {
            cores[4]++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (cores[i] > maior){
            maior = cores[i];
            i_maior = i;
        }
    }
    
    
    for (int i = 0; i < 5; i++)
    {
        printf ("%d: |", i);
        for (int j = 0; j < cores[i]; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }

    for (int j = 0; j < 25; j++)
    {
        if (vet[j] == i_maior){
            printf ("%i\n", j);
        }
    }
    
    

    return 0;
}