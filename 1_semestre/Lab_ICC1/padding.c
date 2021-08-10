#include<stdio.h>
#include<stdlib.h>

void print_img (int height, int width, int **img);

int main () {

    int height = 0, width = 0, padding = 0;

    scanf ("%i", &width);
    scanf ("%i", &height);

    int **img = malloc (height * sizeof(void *));
    for (int i = 0; i < height; i++)
    {
        img[i] = calloc (width, sizeof(int));
        for (int j = 0; j < width; j++)
        {
            scanf ("%i ", &(img[i][j]));
        }
    }

    scanf ("%i", &padding);

    int **img_edit = malloc ((height + (2 * padding)) * sizeof(void *));
    for (int i = 0; i < height + (2 * padding); i++)
    {
        img_edit[i] = calloc ((width + (2 * padding)), sizeof(int));
        for (int j = 0; j < width + (2 * padding); j++)
        {
            if (i < padding || j < padding || i >= (padding + height) || j >= (padding + width))
                img_edit[i][j] = 0;
            else 
                img_edit[i][j] = img[i-padding][j-padding];
        }
    }

    print_img((height + (2 * padding)), (width + (2 * padding)), img_edit);
    printf ("\n");
    print_img(height, width, img);

    for (int j = 0; j < height; j++)
    {
        free(img[j]);
    }
    free(img);
    for (int j = 0; j < height + (2 * padding); j++)
    {
        free(img_edit[j]);
    }
    free(img_edit);
    return 0;
}

void print_img (int height, int width, int **img){
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf ("%i ", img[i][j]);
        }
        printf ("\n");
    }
}