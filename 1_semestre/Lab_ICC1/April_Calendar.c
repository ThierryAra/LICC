// April_calendar
#include<stdio.h>

int main () {

    int date = 0, days_30[30], current = 0;

    scanf ("%d", &date);

    for (int i = 1; i <= 30; i++)
    {
        days_30[i - 1] = i;
        
    }


    printf("         Abril 2021         \n"); // April 2021
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n"); // Su Mo Th We Th Fr Sa 
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // Blank spaces until Thursday of the first week and after the 30th
            if ((i == 0 && j <= 3) || (i == 4 && j > 5)) {
                printf ("    ");
            // Date printing with ( )
            } else if (date == days_30[current]) {
               
                printf ("(%2d)", date);
                current++;
            }
            // Printout of normal days
            else {
                printf (" %2d ", days_30[current]);
                current++;
            }
        }
        printf ("\n");
    }
        
    return 0;
}