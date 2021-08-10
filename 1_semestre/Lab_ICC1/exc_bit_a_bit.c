#include<stdio.h>

int main () {
    int a, b;

    scanf ("%i %i", &a, &b);

    printf ("%i \n", a & b);
    printf ("%i \n", a | b);
    printf ("%i \n", a ^ b);
    printf ("%i \n", ~a);
    printf ("%i \n", ~b);
    printf ("%i \n", a >> 2);
    printf ("%i \n", b << 2);

}

/* 

TEST CASE:

INPUT:
369 24

OUTPUT:
16
377
361
-370
-25
92
96

 */