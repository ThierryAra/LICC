#include<stdio.h>
#include<stdlib.h>
//função time();
#include<time.h>

int main (){

    //time = hora do PC
    srand (time(NULL));
    //gera o numero aleatorio
    rand ();

    int num = rand();

    //valores entre 0 e 9
    int num2 = rand() % 10;

    printf ("%i", num);
    printf ("%i", num2);

    return 0;
}