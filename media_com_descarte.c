#include<stdio.h>
#include<math.h>

int main (){

    double a = 0, b = 0, c = 0, d = 0, min = 0, media = 0;

    scanf ("%lf %lf %lf %lf", &a, &b, &c, &d);

    if (a <= b && a <= c && a <= d){
        min = a;
    } else if (b <= a && b <= c && b <= d){
        min = b;
    }else if (c <= a && c <= b && c <= d){
        min = c;
    }else if (d <= a && d <= b && d <= c){
        min = d;
    }

    media = (a + b + c + d - min)/3;

    printf ("%.4lf", media);

    return 0;
}