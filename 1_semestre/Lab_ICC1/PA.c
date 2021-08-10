#include<stdio.h>

int main () {

    double an, sum;
    int a1, n, r;

    scanf ("%d", &a1);
    scanf ("%d", &r);
    scanf ("%d", &n);

    an = a1 + ((n - 1) * r);

    sum = ((a1 + an) * n)/2;

    printf ("%.0lf ", an);
    printf ("\n%.0lf ", sum);

    return 0;
}

/* 

TEST CASE:

INPUT:
1
1
384

OUTPUT:
384
73920

 */