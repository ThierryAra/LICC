#include<stdio.h>
#include<stdlib.h>

void printar_img (int altura, int largura, int **img);

int main () {

    int altura = 0, largura = 0, padding = 0;

    scanf ("%i", &largura);
    scanf ("%i", &altura);

    int **img = malloc (altura * sizeof(void *));
    for (int i = 0; i < altura; i++)
    {
        img[i] = calloc (largura, sizeof(int));
        for (int j = 0; j < largura; j++)
        {
            scanf ("%i ", &(img[i][j]));
        }
    }

    scanf ("%i", &padding);

    int **img_edit = malloc ((altura + (2 * padding)) * sizeof(void *));
    for (int i = 0; i < altura + (2 * padding); i++)
    {
        img_edit[i] = calloc ((largura + (2 * padding)), sizeof(int));
        for (int j = 0; j < largura + (2 * padding); j++)
        {
            if (i < padding || j < padding || i >= (padding + altura) || j >= (padding + largura))
                img_edit[i][j] = 0;
            else 
                img_edit[i][j] = img[i-padding][j-padding];
        }
    }

    printar_img((altura + (2 * padding)), (largura + (2 * padding)), img_edit);
    printf ("\n");
    printar_img(altura, largura, img);

    for (int j = 0; j < altura; j++)
    {
        free(img[j]);
    }
    free(img);
    for (int j = 0; j < altura + (2 * padding); j++)
    {
        free(img_edit[j]);
    }
    free(img_edit);
    return 0;
}

void printar_img (int altura, int largura, int **img){
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf ("%i ", img[i][j]);
        }
        printf ("\n");
    }
}