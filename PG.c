#include<stdio.h>
#include<math.h>

int main () {

    double a1, an, q, soma;
    int n;

    scanf ("%lf", &a1);
    scanf ("%lf", &q);
    scanf ("%d", &n);

    an = a1 * pow(q, (n - 1));

    soma = (a1 * (pow(q, n) - 1))/ (q - 1);

    printf ("%.2lf ", an);
    printf ("\n%.2lf ", soma);

    return 0;
}