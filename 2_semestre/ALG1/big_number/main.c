#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"big_number.h"
#include"input.h"

int main(){
    char op[4];
    char c = getchar();

    while(c != '\n'){
        ungetc(c, stdin);

        scanf("%s", op);
        c = getchar();
        printf("%c", c);

        B_NUMBER* num1 = create();
        B_NUMBER* num2 = create();
        receive_big_number(num1);
        receive_big_number(num2);

        if(strcmp(op, "SUM") == 0){
            B_NUMBER* sum = SUM(num1, num2);
            print(sum);
            liberate(sum);
        }else if(strcmp(op, "BIG") == 0){
            if(BIG(num1, num2))
                printf("1");
            else
                printf("0");
        }else if(strcmp(op, "SML") == 0){
            if(SML(num1, num2))
                printf("1");
            else    
                printf("0");
        }else if(strcmp(op, "EQL") == 0){
            if(EQL(num1, num2))
                printf("1");
            else    
                printf("0");
        }

        printf("\n");

        print(num1);
        print(num2);

        c = getchar();

        liberate(num1);
        liberate(num2);
    }


    return 0;
}
