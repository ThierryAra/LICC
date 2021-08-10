#include<stdio.h>

void highest (int *vet);

void average (int vet[]);

void smaller (int vet[10]);

void moda (int vet[10]); 

int main (){
    int vet[10];

    for (int i = 0; i < 10; i++)
    {
        scanf ("%i", &vet[i]);
    }

    highest(vet); 
    smaller(vet);
    average(vet);
    moda(vet);

    return 0;
}

void highest (int *vet) {
    int highest = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (highest < vet[i])
            highest = vet[i];
    }

    printf ("%i ", highest);
}

void average (int vet[]) {
    float soma = 0.0;
    for (int i = 0; i < 10; i++)
    {
        soma += vet[i];
    }
    printf ("%.2f ", (soma/10));
}

void smaller (int vet[10]) {
    int smaller = vet[0];
    for (int i = 1; i < 10; i++)
    {
        if (vet[i] < smaller)
            smaller = vet[i];
    }

    printf ("%i ", smaller);
}

void moda (int vet[10]) {
    int repeticao_atual = 0, higher_repetition = 0, moda = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           if (vet[i] == vet[j])
               repeticao_atual++;
        }
        if (repeticao_atual > higher_repetition){
            moda = vet[i];
            higher_repetition = repeticao_atual;
        }

        repeticao_atual = 0;
    }

    printf ("%d", moda);
}