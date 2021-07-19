#include <stdio.h>
#include <stdlib.h>


int topo_pilha = -1;
double *pilha = NULL;
char caracter = ' ';

void calculo ();

int main () {

    while (1)
    {
        caracter = getchar();

        if (caracter == EOF){
            break;
        } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/'){
            calculo ();
            //ao fazer a conta eh desalocado a posicao que continha o segundo numero
            topo_pilha--;
            if (topo_pilha > 0)
                pilha = realloc (pilha, (topo_pilha + 1) * sizeof (double));
            else {
                topo_pilha = 0;
                pilha = realloc (pilha, 1 * sizeof (double));
            }
        } else if (caracter != ' '){
            ungetc (caracter, stdin);
            topo_pilha++;
            pilha = realloc (pilha, (topo_pilha + 1) * sizeof(double));
            scanf ("%lf", &pilha[topo_pilha]);
        }
    }

    printf ("Resultado: %.6lf\n", pilha[topo_pilha]);
    free (pilha);
    return 0;
}

void calculo (){

    switch (caracter)
    {
    case '+':
        pilha[topo_pilha - 1] = pilha[topo_pilha - 1] + pilha[topo_pilha];
        break;
    case '-':
        pilha[topo_pilha - 1] = pilha[topo_pilha - 1] - pilha[topo_pilha];
        break;
    case '*':
        pilha[topo_pilha - 1] = pilha[topo_pilha - 1] * pilha[topo_pilha];
        break;
    case '/':
        pilha[topo_pilha - 1] = pilha[topo_pilha - 1] / pilha[topo_pilha];
    }
}