#include<stdio.h>

int main () {

    int num;
    char and1, and2, and3, and4;

    scanf ("%d", &num);

    and1 = (num >> 24) & 0b11111111;
    and2 = (num >> 16) & 0b11111111;
    and3 = (num >> 8) & 0b11111111;
    and4 = num & 0b11111111;
    
    printf ("%c%c%c%c", and1,and2,and3,and4);

    return 0;
}