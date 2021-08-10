// Coordinates_2D
#include<stdio.h>

int main () {

    char direction[6];
    int y = 0, x = 0;

    scanf ("%s", direction);

    for (int i = 0; i < 6; i++)
    {
        if (direction[i] == 'W'){
            y = y + 1;
        } else if (direction[i] == 'S'){
            y = y - 1;
        } else if (direction[i] == 'A'){
            x = x - 1;
        } else if (direction[i] == 'D'){
            x = x + 1;
        }
    }

    printf ("%i %i", x, y);

    return 0;
}

/* 

TEST CASE:

INPUT:
SSSWAD

OUTPUT:
0 -2

 */