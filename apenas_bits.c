#include<stdio.h>

int main () {

    int num;
    char and1, and2, and3, and4;

    scanf ("%d", &num);

    //como fazer pra pegar os bits iniciais????

    and1 = num & 0b11111111000000000000000000000000;
    and2 = num & 0b00000000111111110000000000000000;
    and3 = num & 0b00000000000000001111111100000000;


    and4 = num & 0b11111111;
    
    printf ("%c \n%c \n%c \n%c", and1,and2,and3,and4);   
    printf ("\n\n%d", and4); 

    return 0;
}