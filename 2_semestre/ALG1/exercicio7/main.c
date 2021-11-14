/*  Exercicio Polinomios
    Thierry de Souza Araujo - 12681094
    USP Sao Carlos - ICMC
    Algoritmo e Estrutuda de Dados I (SCC0202)    */
#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"

int main(){
    LIST_P* list_p;
    
    int amount_tests;
    scanf("%d", &amount_tests);
    int amount_num;

    while (amount_tests > 0){
        scanf("%d", &amount_num);
        clear_buffer();
        
        list_p = create_list();
        
        while (amount_num > 0){
            receive_polynomial(list_p);
            amount_num--;
        }

        LIST_P* list_sum = calculate(list_p);

        print(list_sum->start);
        liberate_list(list_p);
        liberate_list(list_sum);

        amount_tests--;
    }

    return 0;
}