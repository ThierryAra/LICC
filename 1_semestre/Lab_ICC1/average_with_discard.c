#include<stdio.h>
#include<math.h>

int main (){

    double a = 0, b = 0, c = 0, d = 0, minimum = 0, average = 0;

    scanf ("%lf %lf %lf %lf", &a, &b, &c, &d);

    minimum = a;
    if (minimum > b) minimum = b;
    if (minimum > c) minimum = c;
    if (minimum > d) minimum = d;

    average = (a + b + c + d - minimum)/3;

    printf ("%.4lf", average);

    return 0;
}