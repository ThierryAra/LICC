// Simple_calculator
#include<stdio.h>

int main (){

    float number1, number2;
    char operator;

    scanf ("%f %c %f", &number1, &operator, &number2);

    switch (operator)
    {
    case '+':
        printf ("%.6f\n", (number1 + number2));
        break;
    case '-':
        printf ("%.6f\n", (number1 - number2));
        break;
    case '*':
        printf ("%.6f\n", (number1 * number2));
        break;
    case '/':
        printf ("%.6f\n", (number1 / number2));
        break;
    case '%':
        printf ("%.6f\n", ((100*number1)/number2) );
        break;
    }

    return 0;
}