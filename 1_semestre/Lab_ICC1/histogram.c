// Histogram
#include<stdio.h>

int main () {

    int vet[25], colors[5] = {0, 0, 0, 0, 0}, biggest = 0, index_of_highest = 0;

    for (int i = 0; i < 25; i++)
    {
        scanf ("%i", &vet[i]);
        if (vet[i] == 0){
            colors[0]++;
        } else if (vet[i] == 1){
            colors[1]++;
        } else if (vet[i] == 2){
            colors[2]++;
        } else if (vet[i] == 3){
            colors[3]++;
        } else {
            colors[4]++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (colors[i] > biggest){
            biggest = colors[i];
            index_of_highest = i;
        }
    }
    
    
    for (int i = 0; i < 5; i++)
    {
        printf ("%d: |", i);
        for (int j = 0; j < colors[i]; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }

    for (int j = 0; j < 25; j++)
    {
        if (vet[j] == index_of_highest){
            printf ("%i\n", j);
        }
    }
    
    

    return 0;
}