#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main() {

    fila_t* f;    
    f = criar();

    for (int i = 0; i < 10; i++)
        insert(f, i);

    elem x;

    remover(f, &x);
    printf("%d ", x);
    remover(f, &x);
    printf("%d \n", x);

    insert(f, 11);

    while (!is_empty(f)) {
        remover(f, &x);
        printf("%d ", x);
    }
    printf("\n");

    excluir(f);

    return 0;
}