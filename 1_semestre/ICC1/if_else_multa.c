#include<stdio.h>

int main (){

    float velocidade, multa, limite = 80;

    scanf ("%f", &velocidade);
    
    if (velocidade > limite){
        multa = 2 * (velocidade - limite);
        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!", multa);
    } else{
        printf("Velocidade dentro do limite permitido.");
    }
    
    return 0;
}