#include<stdio.h>

int main () {

    int x1, x2, y1, y2, larg1, alt1, larg2, alt2;
    int i, j;

    scanf ("%d %d %d %d", &x1, &y1, &larg1, &alt1);
    //scanf ("%d %d %d %d", &x2, &y2, &larg2, &alt2);

    int matriz1[10][10], matriz2[larg2][alt2];

    i = x1 + larg1;
    j = y1 + alt1;

    for ( x1; x1 >= i; x1++ ){
        for ( y1; y1 >= j; y1++ ){
            matriz1[ x1 ][ y1 ] = x1 + y1;
            printf ("%d \t", matriz1[ x1 ][ y1 ]);
        }
        printf ("\n");
    }

    return 0;
}