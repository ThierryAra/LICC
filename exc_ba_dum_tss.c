#include<stdio.h>

int main () {

    int num, div11, div13, div19;

    scanf ("%i", &num);

    div11 = num % 11; 
    div13 = num % 13; 
    div19 = num % 19;

   if (div11 == 0 && div13 == 0 && div19 == 0){
       printf ("BaDumTssTss");
    } else if (div11 == 0 && div13 == 0){
       printf ("BaDumDum");
    } else if (div11 == 0 && div19 == 0){
       printf ("BaDumTss");
    } else if (div13 == 0 && div19 == 0){
       printf ("DumDumTss");
    } else if (div11 == 0){
       printf ("BaBa");
    } else if (div13 == 0){
       printf ("BaDum");
    } else if (div19 == 0){
       printf ("BaTss");
    } else {
        printf ("%i", num);
    }
}
