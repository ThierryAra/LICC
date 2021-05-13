#include<stdio.h>

int main () {

    char dir[6];
    int y = 0, x = 0;

    scanf ("%s", dir);

    for (int i = 0; i < 6; i++)
    {
        if (dir[i] == 'W'){
            y = y + 1;
        } else if (dir[i] == 'S'){
            y = y - 1;
        } else if (dir[i] == 'A'){
            x = x - 1;
        } else if (dir[i] == 'D'){
            x = x + 1;
        }
    }

    printf ("%i %i", x, y);

    return 0;
}