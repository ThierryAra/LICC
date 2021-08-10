#include<stdio.h>
#include<math.h>

int main () {

    double a1, an, q, sum;
    int n;

    scanf ("%lf", &a1);
    scanf ("%lf", &q);
    scanf ("%d", &n);

    an = a1 * pow(q, (n - 1));

    sum = (a1 * (pow(q, n) - 1))/ (q - 1);

    printf ("%.2lf ", an);
    printf ("\n%.2lf ", sum);

    return 0;
}
/* 

TEST CASE:

INPUT:
0.56
0.85
7

OUTPUT:
0.21
2.54

 */