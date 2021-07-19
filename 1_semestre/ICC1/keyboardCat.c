#include<stdio.h>
#define A 49
int main () {

    char vet[A];

    for (int i = 0; i < A; i++)
    {
        scanf (" %c ", &vet[i]);
    }
    
    int num = 0;

    scanf ("%i", &num);

    int cod[num];

    for (int i = 0; i < num; i++)
    {
        scanf ("%i", &cod[i]);
    }
    
    for (int i = 0; i < num; i++)
    {
        //printf ("Vet[%d] = ", i);
        for (int j = 0; j < A; j++)
        {
            if (j == cod[i]){
                if (vet[j] == '_'){
                    printf (" ");
                } else if (vet[j] == 'E'){
                    printf ("\n");
                } else {
                    printf ("%c", vet[j]);
                    break;
                }
            }
        }
        //printf ("\n");
    }
    
    //printf ("%c", vet[38]);

    return 0;
}