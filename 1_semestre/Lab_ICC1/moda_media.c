#include<stdio.h>

void maior (int *vet) {
    int maior = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (maior < vet[i])
            maior = vet[i];
    }

    printf ("%i ", maior);
}

void media (int vet[]) {
    float soma = 0.0;
    for (int i = 0; i < 10; i++)
    {
        soma += vet[i];
    }
    printf ("%.2f ", (soma/10));
}

void menor (int vet[10]) {
    int menor = vet[0];
    for (int i = 1; i < 10; i++)
    {
        if (vet[i] < menor)
            menor = vet[i];
    }

    printf ("%i ", menor);
}

void moda (int vet[10]) {
    int repeticao_atual = 0, maior_repeticao = 0, moda = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           if (vet[i] == vet[j])
               repeticao_atual++;
        }
        if (repeticao_atual > maior_repeticao){
            moda = vet[i];
            maior_repeticao = repeticao_atual;
        }

        repeticao_atual = 0;
    }

    printf ("%d", moda);
}

int main (){
    int vet[10];

    for (int i = 0; i < 10; i++)
    {
        scanf ("%i", &vet[i]);
    }

    maior(vet); 
    menor(vet);
    media(vet);
    moda(vet);

    return 0;
}