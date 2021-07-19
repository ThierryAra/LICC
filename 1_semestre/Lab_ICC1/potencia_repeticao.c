#include<stdio.h>

int main () {

    int base = 0, exp = 0, res = 1, i = 0;

    scanf ("%i %i", &base, &exp);

    if (exp != 0){
        while (exp != i)
        {
            i++;
            res = res * base;
        }
        
        printf ("%i", res);
    } else {
        printf ("%i", res);
    }

    return 0;
}