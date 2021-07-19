#include<stdio.h>

int main () {

    int vet[512], i = 0;

    for (int i = 0; i < 512; i++)
    {
        scanf ("%d", &vet[i]);
    }
    
    printf ("Saida do programa:\n"); 

    while (vet[i] != 0 || i > 512)
    {
    
        switch (vet[i]) {
            case 1:
                vet[vet[i+3]] = vet[vet[i+1]] + vet[vet[i+2]];
                i = (i + 3);
                break;
            case 2:
                vet[vet[i+3]] = vet[vet[i+1]] * vet[vet[i+2]];
                i = (i + 3);
                break;
            case 3:
                if (vet[vet[i+1]] < vet[vet[i+2]])
                    vet[vet[i+3]] = 1;
                else 
                    vet[vet[i+3]] = 0;
                i = (i + 3);
                break;
            case 4:
                if (vet[vet[i+1]] == vet[vet[i+2]])
                    vet[vet[i+3]] = 1;
                else 
                    vet[vet[i+3]] = 0;
                i = (i + 3);
                break;
            case 5:
                i = vet[vet[i+1]] - 1;
                break;
            case 6:
                if (vet[vet[i+1]] != 0)
                    i = vet[vet[i+2]] - 1;
                else
                    i = i + 2;
                break;
            case 7:
                vet[vet[i+2]] = vet[vet[i+1]];
                i = i + 2;
                break;
            case 8:
                printf ("%c", vet[vet[i+1]]);
                i++;
                break;
            case 9:
                printf ("%d", vet[vet[i+1]]);
                i++;
                break;
        }
       
        i++;
    }
    printf ("\nEstado final da fita:\n");
    
    for (int i = 0; i < 512; i++)
    {
        printf ("%d\n", vet[i]);
    }
    return 0;
}