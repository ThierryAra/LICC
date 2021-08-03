#include <stdio.h>

int main () {

    int triangle_height = 0, j = 1, odd[25];
    char character;

    // Finding the first 25 odd
    for (int i = 1, j = 0; i < 50; i = i + 2, j++) odd[j] = i;
    

    scanf (" %i", &triangle_height);
    scanf (" %c", &character);

    // Variable to determine spaces before each line
    int line_start = triangle_height - 1;

    if (triangle_height > 25 || triangle_height <= 0){
        printf ("Altura invalida\n"); //Invalid height
    }else {

        for (int i = 0; i < triangle_height; i++)
        {
            // Generating spaces before each line
            while (j <= line_start){
                printf (" ");
                j++;
            }

            line_start = line_start - 1;
            j = 1;

            for (int k = 1; k <= odd[i]; k++){
                printf ("%c", character);
            }
           
            printf ("\n");
        }
    
    } 
    return 0;
}

/* 

CASE TEST:

INPUT
3
$

OUTPUT:
  $
 $$$
$$$$$

 */