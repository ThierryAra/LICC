#include<stdio.h>

int main () {

    double an, soma;
    int a1, n, r;

    scanf ("%d", &a1);
    scanf ("%d", &r);
    scanf ("%d", &n);

    an = a1 + ((n - 1) * r);

    soma = ((a1 + an) * n)/2;

    printf ("%.0lf ", an);
    printf ("\n%.0lf ", soma);

    return 0;
}