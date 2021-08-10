// Lisp_Calculator
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

//void calculate (double *num1, double num2, char operator);
double calculate (float *numbers, int amount_numbers, char *operator, int amount_operators);

int main (){

    char current_char, *operator = NULL;
    int amount_operators = 0, amount_numbers = 0;
    double *numbers = NULL, result = 0;

    do {
        do {
            current_char = getchar();

            if (isdigit(current_char)){

                ungetc (current_char, stdin);
                amount_numbers++;
                numbers = realloc (numbers, amount_numbers * sizeof(double));
                scanf ("%lf", &numbers[amount_numbers - 1]);

            } else if ((current_char != ')') && (current_char != '(') && (current_char != ' ')){

                amount_operators++;
                operator = realloc (operator, amount_operators * sizeof(char));
                operator[amount_operators - 1] = current_char;

            } else if (current_char == ')'){
                
                /* if (amount_numbers >= 2 && amount_operators >= 1){

                    //calculate(&numbers[amount_numbers-2], numbers[amount_numbers-1], operator[amount_operators-1]);
                    
                    amount_numbers -= 1;
                    amount_operators -= 1;
                    if (amount_operators == 0)
                        amount_operators = 1;
                    
                    numbers = realloc (numbers, amount_numbers * sizeof(double));
                    operator = realloc (operator, amount_operators * sizeof(char));
                } */
                        
            }
        } while (current_char != '\n');
        
        result = calculate (numbers, amount_numbers, operator, amount_operators);
        printf ("%.6lf\n", result);
        amount_numbers = 0;
        amount_operators = 0;
        current_char = getchar();
        if (current_char != EOF) ungetc (current_char, stdin);
    } while (current_char != EOF);

    free (numbers);
    free (operator);    

    return 0;
}

/* void calculate (double *num1, double num2, char operator){     
    switch (operator) {
        case '+':
            *num1 = *num1 + num2; 
            break;
        case '-':
            *num1 = *num1 - num2; 
            break;
        case '*':
            *num1 = *num1 * num2; 
            break;
        case '/':
            *num1 = *num1 / num2; 
            break;
    }
} */

double calculate (float *numbers, int amount_numbers, char *operator, int amount_operators){
    double result;
    //int index_operator = amount_operators, index_numbers = amount_numbers;

    while ((amount_operators - 1) != 1) {
        switch (operator[amount_operators - 1]) {
            case '+':
                result = numbers[amount_numbers - 2] + numbers[amount_numbers - 1];
                break;
            case '-':
                result = numbers[amount_numbers - 2] - numbers[amount_numbers - 1]; 
                break;
            case '*':
                result = numbers[amount_numbers - 2] * numbers[amount_numbers - 1]; 
                break;
            case '/':
                result = numbers[amount_numbers - 2] / numbers[amount_numbers - 1]; 
                break;
        }
        result += calculate (numbers, amount_numbers - 2, operator, amount_operators - 1);
    }

    return result;
}