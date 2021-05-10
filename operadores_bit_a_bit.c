#include<stdio.h>

int main() {

    // & e
    // | ou
    // ^ ou exclusivo
    // << deslocamento a esquerda
    // >> deslocamento a direita
    // ~  complemento


    int num = 10, num2 = 15;

    /* 
        10 em bin = 00001010
        15 em bin = 00001111
        &         = 00001010 (0 & 1 = 0, 1 & 1 = 1, 0 & 0 = 0)
        |         = 00001010 (0 | 1 = 1, 1 | 1 = 1, 0 | 0 = 0)
        ^         = 00001010 (0 ^ 1 = 1, 1 ^ 1 = 0, 0 ^ 0 = 0)
    */

    printf ("& %i \n", num & num2);
    printf ("| %i \n", num | num2);
    printf ("^ %i \n", num ^ num2);

    /*
        8 em bin = 00001000
            << 1 = 00000100 = 4  (vai um 0  para a esquerda)
            >> 1 = 00010000 = 16 (vai um 0 para a direita)
            ~    = 11110111 =-11 (último dígito é o sinal)
            
    */

    printf ("<< %i \n", num >> 1);
    printf (">> %i \n", num << 1);
    printf ("~ %i \n", ~num);


}