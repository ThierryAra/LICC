// Leap Year
#include<stdio.h>

int main () {

    int year;

    scanf ("%d", &year);

    if (year % 4 == 0)
        printf ("SIM"); // YES
    else 
        printf ("NAO"); // NO

    return 0;
}