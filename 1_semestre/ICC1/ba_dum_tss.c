#include<stdio.h>

int main () {

    int num, division_11, division_13, division_19;

    scanf ("%i", &num);

    division_11 = num % 11; 
    division_13 = num % 13; 
    division_19 = num % 19;

   if (division_11 == 0 && division_13 == 0 && division_19 == 0){
       printf ("BaDumTssTss");
    } else if (division_11 == 0 && division_13 == 0){
       printf ("BaDumDum");
    } else if (division_11 == 0 && division_19 == 0){
       printf ("BaDumTss");
    } else if (division_13 == 0 && division_19 == 0){
       printf ("DumDumTss");
    } else if (division_11 == 0){
       printf ("BaBa");
    } else if (division_13 == 0){
       printf ("BaDum");
    } else if (division_19 == 0){
       printf ("BaTss");
    } else {
        printf ("%i", num);
    }
}

/* 
CASE TEST:

INPUT: 605891

OUTPUT: BaDumTssTss
 */