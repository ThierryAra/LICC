#include<stdio.h>

int main () {

     int mordida = 0, brincada = 0, peso_perdido = 0;

    scanf ("%i %i", &brincada, &mordida);

    peso_perdido = (brincada * 5) - (mordida * 3) ;

    if (peso_perdido > 30){
        printf ("P");
    } else if (peso_perdido >= 0 && peso_perdido <= 30){ 
        printf("B");
    } else {
        printf ("R");
    }

    return 0;
}