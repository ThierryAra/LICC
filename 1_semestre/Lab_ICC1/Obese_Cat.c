// Obese_cat
#include<stdio.h>

int main () {

     int bite = 0, play = 0, weight_loss = 0;

    scanf ("%i %i", &play, &bite);

    weight_loss = (play * 5) - (bite * 3) ;

    if (weight_loss > 30){
        printf ("P");
    } else if (weight_loss >= 0 && weight_loss <= 30){ 
        printf("B");
    } else {
        printf ("R");
    }

    return 0;
}

/* 

TEST CASE:

INPUT:
3 4

OUTPUT:
B

 */