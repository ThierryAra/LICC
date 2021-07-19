#include<stdio.h>
#define linha 32
#define col 65

void print_matriz (int v, char matriz[linha][col]) {

    if (v == -1){
        printf ("Falha na esteira.\n");
    } else if (v == 0) {
        printf ("Ok.\n");
    }
    else {
        printf ("Loop infinito.\n");
    }
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col-1; j++)
        {
            printf ("%c", matriz[i][j]);
        }
        printf ("\n");
    }

}
int main () {

    char matriz[linha][col], anterior;
    int coluna_inicio = 0, linha_inicio = 0;

    //atribui espaco em branco no matriz inteiro
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < col; j++)
        {
            matriz[i][j] = 32;
        }
    }

    //preenchendo a matriz
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf ("%c", &matriz[i][j]);
            if (matriz[i][j] == '['){
                linha_inicio = i;
                coluna_inicio = j;
            }
            //se a matriz ler um enter descera uma linha
            if (matriz[i][j] == '\n'){
                break;
            }
        } 
    }

    //continua transformando enquanto nao leu toda a matriz ou nao leu nenhum ponto
    for (int i = linha_inicio; i < linha; i++)
    {
        for (int j = coluna_inicio; j < col; j++)
        {  
            if (matriz[i][j] == '.'){
                print_matriz(1, matriz);
                return 0;
            }

            if (matriz[i][j] == '>'){
                
                anterior = '>';
                matriz[i][j] = '.';
                //verifica se a proxima posicao e vazia
                if (matriz[i][j + 2] == ' ') {
                    print_matriz (-1, matriz);
                    return 0;
                }
                //verifica loop do tipo  ><
                if (matriz[i][j + 2] == '<'){
                    matriz[i][j + 2] = '.';
                    print_matriz(1, matriz);
                    return 0;
                }
                //finaliza caso encontre ]
                if (matriz[i][j + 2] == ']'){
                    print_matriz(0, matriz);
                    return 0;
                }
                j++;

            } else if (matriz[i][j] == 'v'){
               
                anterior = 'v';
                matriz[i][j] = '.';
                //verifica se a proxima posicao e vazia
                if (matriz[i + 1][j] == ' ') {
                    print_matriz (-1, matriz);
                    return 0;
                }
                coluna_inicio = j;
                break;

            } else if (matriz[i][j] == '^'){

                anterior = '^';
                matriz[i][j] = '.';
                //verifica se a proxima posicao e vazia
                if (matriz[i - 1][j] == ' ') {
                    print_matriz (-1, matriz);
                    return 0;
                }
                i = i - 2;
                coluna_inicio = j;
                break;

            } else if (matriz[i][j] == '<'){
                
                anterior = '<';
                matriz[i][j] = '.';
                //verifica se a proxima posicao e vazia
                if (matriz[i][j - 2] == ' ') {
                    print_matriz (-1, matriz);
                    return 0;
                }
                j = j - 3;

            } else if (matriz[i][j] == '#'){

                if (anterior == '>'){
                    j++;
                } else if (anterior == '^'){
                    i = i - 2;
                    coluna_inicio = j;
                    break;
                } else if (anterior == 'v'){
                    coluna_inicio = j;
                    break;
                } else if (anterior == '<'){
                    j = j - 3;
                }
            }
        }
    }

    print_matriz(0, matriz);
    return 0;
}