#include<stdio.h>
#define SIZE_VET 49
int main () {

    char vet[SIZE_VET];

    for (int i = 0; i < SIZE_VET; i++)
    {
        scanf (" %c ", &vet[i]);
    }
    
    int size_cod = 0;

    scanf ("%i", &size_cod);

    int code[100];

    for (int i = 0; i < size_cod; i++)
    {
        scanf ("%i", &code[i]);
    }
    
    for (int i = 0; i < size_cod; i++)
    {
        for (int j = 0; j < SIZE_VET; j++)
        {
            if (j == code[i]){
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
    }

    return 0;
}