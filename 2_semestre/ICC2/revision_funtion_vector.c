//USP SÃO CARLOS
//THIERRY DE SOUZA ARAUJO - 12681094

#include<stdio.h>

void count_numbers (int numbers[100], int amount_numbers);

int main () {

    int numbers[100], amount_numbers = 0, stop;

    while(stop != EOF) {
        stop = scanf ("%d", &numbers[amount_numbers]);
        amount_numbers++;
    }

    count_numbers(numbers, amount_numbers - 1);

    return 0;
}

void count_numbers (int numbers[100], int amount_numbers){

    int analyzed_number, amount_repeated_number;
    
    for (int i = 0; i < amount_numbers; i++) {
        amount_repeated_number = 0;
        analyzed_number = numbers[i];
        if (i == 0){
            for (int j = 0; j < amount_numbers; j++) {
                if (numbers[i] == numbers[j])
                    amount_repeated_number++;
            }
        } else if (analyzed_number != numbers[0]){ //Ensures that you analyze only uncounted numbers
            for (int j = 0; j < amount_numbers; j++) {
                if (analyzed_number == numbers[j]){
                    amount_repeated_number++;
                    numbers[j] = numbers[0]; //Makes it possible to check the else if
                }
            }
        }
        
        if (amount_repeated_number != 0) 
            printf ("%d (%d)\n", analyzed_number, amount_repeated_number);
    }
} 


/*

CASE TEST: 

INPUT:
9 8 7 4 3 -2 1 0

OUTPUT:
9 (1)
8 (1)
7 (1)
4 (1)
3 (1)
-2 (1)
1 (1)
0 (1)

*/