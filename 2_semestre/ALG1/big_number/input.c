#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"input.h"

int receive_big_number(B_NUMBER* b_n){
    char* node = malloc(5 * sizeof(char));
    char c;
    int i = 0; 

    c = getchar();

    if(c == '-'){
        b_n->signal = 1;
        c = getchar();
    }else{
        b_n->signal = 0;
    }

    while(c != ' ' && c != '\n' && c != EOF){
        node[i++] = c;

        if(i == 4){
            node[i] = '\0';
            int int_node = atoi(node);
            insert(b_n, int_node);;
            i = 0;
            node[i] = '\0';
        }

        c = getchar();
    }

    if(node[0] != '\0'){
        node[i] = '\0';
        int int_node = atoi(node);
        insert(b_n, int_node);
    }

    if(c == '\n')
        c = getchar();

    free(node);
    return 1;
}

void receive_string(char* string, int mode){
    char letter = getchar();

    int i = 0;
    if(mode == 0){
        while(letter != '\r' && letter != '\n' && letter != ' ' && letter != EOF){
            string[i] = letter;
            letter = getchar();
            i++;
        }
    }else{
        while(letter != '\r' && letter != '\n' && letter != EOF){
            string[i] = letter;
            letter = getchar();
            i++;
        }
    }

    string[i] = '\0';

    if(letter == '\r') getchar();

    if(letter == EOF) ungetc(letter, stdin);
} 
