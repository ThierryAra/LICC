#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(int argc, char const *argv[])
{
    printf("Tipo dados vars\n");
    printf("\tChar: %lu byte(s)\n", sizeof(char));
    printf("\tInt: %lu byte(s)\n", sizeof(int));
    printf("\tFloat: %lu byte(s)\n", sizeof(float));
    printf("\tDouble: %lu byte(s)\n", sizeof(double));

    printf("Range das variáveis:\n");
    printf("\tChar: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("\tInt: [%d, %d]\n", INT_MIN, INT_MAX);
    //%f não pois é muito grande, %e está em notação científica. Mostram a precisão (lim x->0);
    printf("\tFloat: [%e, %e]\n", FLT_MIN, FLT_MAX);
    printf("\tDouble: [%e, %e]\n", DBL_MIN, DBL_MAX);

    //Numa operação, a váriavel abaixo na hierarquia é tranformada na maior
}