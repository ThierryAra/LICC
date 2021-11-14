#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Selects and returns enough space to store the matrix */
int** generating_image(int height, int width);

/* Receive on input, data for filling the matrix */
void receiving_image(int** image, int height, int width);

/* Will subdivide the matrix into 4 matrices, until all values 
   in a subdivision are equal, or that the subdivision is unitary
   PARAMETERS:
    image: matrix containing the data for analysis
    x_b  : beginning of the x-axis at a subdivision
    x_e  : end of the x-axis at a subdivision 
    y_b  : beginning of the y-axis at a subdivision 
    y_e  : end of the y-axis at a subdivision */
void quad_tree(int** image, int x_b, int x_e, int y_b, int y_e);

/* Frees the memory allocated to the matrix image */
void free_image(int** image, int height);

int main(){
    int height, width;
    scanf("%d %d", &height, &width);

    int** image = NULL;
    image = generating_image(height, width);

    receiving_image(image, height, width);

    quad_tree(image, 0, width, 0, height);

    free_image(image, height);
}

int** generating_image(int height, int width){
    int **image;

    image = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        image[i] = malloc(width * sizeof(int));

    return image;
}

void receiving_image(int** image, int height, int width){
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            scanf("%d", &image[i][j]);
}

void quad_tree(int** image, int x_b, int x_e, int y_b, int y_e){
    //Case the next division will be unitary
    if(((y_e - y_b) + (x_e - x_b)) == 4){
        if(    image[y_b][x_b] == image[y_b][x_b + 1]
            && image[y_b][x_b] == image[y_b + 1][x_b]
            && image[y_b][x_b] == image[y_b + 1][x_b + 1])
            printf("%d ", image[y_b][x_b]);
        else{
            printf("-1 ");
            printf("%d ", image[y_b][x_b]);
            printf("%d ", image[y_b][x_b + 1]);
            printf("%d ", image[y_b + 1][x_b]);
            printf("%d ", image[y_b + 1][x_b + 1]);
        }

        return;
    }
    
    int value = image[y_b][x_b];
    bool equal = true;
    
    for (int i = y_b; i < y_e && equal == true; i++){
        for (int j = x_b; j < x_e; j++){
            if(value != image[i][j]){
                equal = false;
                break;
            }
        }
    }

    //If all values are equal
    if(equal == true){
        printf("%d ", value);
        return;
    }

    //New division
    printf("-1 ");
    quad_tree(image, x_b, (int)((x_e + x_b)/2), y_b, (int)((y_e + y_b)/2)); //2° quadrant
    quad_tree(image, (int)((x_e + x_b)/2), x_e, y_b, (int)((y_e + y_b)/2)); //1° quadrant
    quad_tree(image, x_b, (int)((x_e + x_b)/2), (int)((y_e + y_b)/2), y_e); //3° quadrant
    quad_tree(image, (int)((x_e + x_b)/2), x_e, (int)((y_e + y_b)/2), y_e); //4° quadrant
}

void free_image(int** image, int height){
    for (int i = 0; i < height; i++)
        free(image[i]);
    free(image);
    
    image = NULL;
}