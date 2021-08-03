#include<stdio.h>

int main (){

    float velocity, fine, limit = 80;

    scanf ("%f", &velocity);
    
    if (velocity > limit){
        fine = 2 * (velocity - limit);
        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!", fine);
    } else{
        printf("Velocidade dentro do limite permitido.");
    }
    
    return 0;
}