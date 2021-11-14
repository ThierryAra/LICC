#include<stdio.h>
#include "editar_conjunto.h"
#include "operacoes.h"

int main (){

    sint *A, *B, *C;

    A = criar_conjunto();
    B = criar_conjunto();
    C = criar_conjunto();

    eliminar_conjunto(C);

    C = diferenca (A, B);

    imprimir(A);
    imprimir(B);
    imprimir(C);

    int num = 12;
    if (verificar_membro(C, num) == true){
        printf ("\nNúmero %2d encontrado\n", num);
        remover_numero(C, num);
        imprimir(C);
    }
    else {
        printf ("\nNúmero %2d nao encontrado\n", num);
        inserir_membro(C, num);
        imprimir(C);
    }

    printf ("\nMaior valor de C: %2i \n", max_valor(C));
    printf ("\nMenor valor de C: %2i \n", min_valor(C));      

    if (verificar_igualdade(A, B) == 1)
        printf ("\nOs conjuntos sao identicos\n");
    else 
        printf ("\nOs conjuntos nao sao identicos\n");

    
    eliminar_conjunto(C);
    eliminar_conjunto(B);
    eliminar_conjunto(A);
    return 0;
}