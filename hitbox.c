#include<stdio.h>

int main () {

    long int x1, y1, larg1, alt1, x2, y2, larg2, alt2;
    long int x1max, y1max, x2max, y2max;
    long int xi, yi, largi, alti;

    scanf ("%ld %ld %ld %ld", &x1, &y1, &larg1, &alt1);
    scanf ("%ld %ld %ld %ld", &x2, &y2, &larg2, &alt2);

    x1max = x1 + larg1;
    y1max = y1 + alt1;
    x2max = x2 + larg2;
    //printf ("%ld\n", x1max);
    y2max = y2 + alt2;

    if (x2 > x1max || x1 > x2max || y1 > y2max || y2 > y1max){
        printf ("MISS");
        return 0;
    } 

    if (x2 > x1 && x1max >= x2){
        xi = x2;
        if (x2max > x1max){
            largi = x1max - x2;
        } else if (x1max == x2){
            largi = 0;
        } else {
            largi = larg2;
        }
    } else if (x1 > x2 && x2max >= x1){
        xi = x1;
        if (x1max > x2max){
            largi = x2max - x1;
        } else if (x2max == x1){
            largi = 0;
        } else {
            largi = larg1;
        }
    } else if (x1 == x2 && x1max > x2max){
        xi = x1;
        largi = larg2;
    } else {
        xi = x1;
        largi = larg1;
    }

    if (y2 > y1 && y1max >= y2){
        yi = y2;
        if (y2max > y1max){
            alti = y1max - y2;
        } else if (y1max == y2){
            alti = 0;
        } else {
            alti = alt2;
        }
    } else if (y1 > y2 && y2max >= y1){
        yi = y1;
        if (y1max > y2max){
            alti = y2max - y1;
        } else if (y2max == y1){
            largi = 0;
        } else {
            alti = alt1;
        }
    } else if (y1 == y2 && y1max > y2max){
        yi = y1;
        alti = alt2;
    } else {
        yi = y1;
        alti = alt1;
    }

    printf ("HIT: %ld %ld %ld %ld", xi, yi, largi, alti);

    return 0;
}