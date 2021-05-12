#include <stdio.h>

int main () {

    int a = 10;
    //declaração de ponteiro
    int *var_pointer;

    //ponteiro recebendo o endereço de a
    var_pointer = &a;

    printf ("Valor de a = %d, endereco = %p \n\n", a, &a);
    printf ("Valor de Var_pointer = %p, endereco = %p\n\n", var_pointer, &var_pointer);
    //com o * no printf, será printado o valor q está no endereço de var_pointer
    printf ("%d", *var_pointer);

}