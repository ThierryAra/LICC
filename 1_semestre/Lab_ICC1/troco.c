#include<stdio.h>

void calculate_minimum_change (int *real, int *cent_50, int *cent_25, int *cent_10, int *cent_5, int *cent_1, int troco){

    *real = (int)(troco / 100);
    troco -= (*real * 100);
    if (troco != 0){
        *cent_50 = (int)(troco / 50);
        troco -= (*cent_50 * 50);
        if (troco != 0){
            *cent_25 = (int)(troco / 25);
            troco -= (*cent_25 * 25);
            if (troco != 0){
                *cent_10 = (int)(troco / 10);
                troco -= (*cent_10 * 10);
                if (troco != 0){
                    *cent_5 = (int)(troco / 5);
                    troco -= (*cent_5 * 5);
                    if (troco != 0){
                        *cent_1 = (int)(troco / 1);
                        troco -= *cent_1;
                    }
                }
            }
        }
    }
}

int main (){

    int real = 0, cent_50 = 0, cent_25 = 0, cent_10 = 0, cent_5 = 0, cent_1 = 0, troco = 0;

    scanf ("%i", &troco);

    // The change is given in cents, so you divide it by 100
    real = (int)(troco / 100);

    calculate_minimum_change(&real, &cent_50, &cent_25, &cent_10, &cent_5, &cent_1, troco);

    printf ("O valor consiste em %d moedas de 1 real\n", real);
    printf ("O valor consiste em %d moedas de 50 centavos\n", cent_50);
    printf ("O valor consiste em %d moedas de 25 centavos\n", cent_25);
    printf ("O valor consiste em %d moedas de 10 centavos\n", cent_10);
    printf ("O valor consiste em %d moedas de 5 centavos\n", cent_5);
    printf ("O valor consiste em %d moedas de 1 centavo\n", cent_1);
    

    return 0;
}