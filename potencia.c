#include<stdio.h>
#include<math.h>

int main (){

    float base, exp, resultado;

    scanf ("%f %f", &base, &exp);

    resultado = pow(base, exp);

    printf ("%.4f", resultado);

    return 0;
}