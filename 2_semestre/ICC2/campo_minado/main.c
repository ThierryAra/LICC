// Exercicio Campo Minado
// Thierry de Souza Araujo
// ICMC - USP Sao Carlos
// Introducao a Ciencia da Computacao II (SCC0201)

#include<stdio.h>
#include<stdlib.h>
#include"editar_campo.h"

int main (){
    int operacao = 0;
    char nome_jogo[8];
    scanf ("%d", &operacao);
    scanf (" %s", nome_jogo);
    
    JOGO* jogo;
    jogo = criar_campo();
    receber_jogo(jogo, nome_jogo);

    switch (operacao) {
        case 1:
            imprimir_campo(jogo);
            break;
        case 2:
            gerar_campo_dicas(jogo);
            exibir_dicas(jogo);
            break;
        case 3:
            gerar_campo_dicas(jogo);
            int coord_x = 0, coord_y = 0;
            scanf ("%d %d", &coord_y, &coord_x);
            acao(jogo, coord_y, coord_x);
        default:
            break;
    }

    excluir_tabuleiro(jogo);

    return 0;
}