/*  Exercicio Bando de Memória
    Thierry de Souza Araujo - 12681094
    USP Sao Carlos - ICMC
    Algoritmo e Estrutuda de Dados I (SCC0202)    */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"memory_bank.h"
#include"person.h"

int main(){

    char op[8];

    MEM_BANK* mem_bank = create_bank();
    person_t person;
    
    char end = getchar();

    while(end != EOF){
        ungetc(end, stdin);
        scanf("%s", op);
        getchar();
        
        if(strcmp(op, "INSERE") == 0){
            scanf("%d", &person.ID);
            getchar();
            scanf("%[^\r]", person.name);
            getchar();
            
            int penultimate;
            if(search_ID(mem_bank, person.ID, &penultimate) == -2)
                insert_sorted(mem_bank, person);
            else
                printf("INVALIDO\n");

        }else if(strcmp(op, "REMOVE") == 0){
            int ID;
            scanf("%d", &ID);
            getchar();

            if(remove_ID(mem_bank, ID) != 1)
                printf("INVALIDO\n");

        }else if(strcmp(op, "IMPRIMIR") == 0){
            getchar();
            if(print_people(mem_bank) == 0)
                printf("VAZIA\n");
        } 

        end = getchar();
    }
    
    liberate(mem_bank);
    return 0;
}