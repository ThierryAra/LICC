#include<stdio.h>

int main () {

    int mordida = 0, brincada = 0;
    float peso_final = 0.0;

    scanf ("%d %d", &brincada, &mordida);

    peso_final = (brincada * 5) - (mordida * 3);
    
    if (peso_final < 30){
        printf ("P");
    } else if (peso_final == 30){ 
        printf("B");
    } else {
        printf ("R");
    }

    return 0;
}