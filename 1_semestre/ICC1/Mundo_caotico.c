#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define troca(matriz, yo, xo, y, x) ({int c = matriz[y][x]; matriz[y][x] += matriz[yo][xo];  matriz[yo][xo] += c;})

void reiniciar_vizinhanca(int lin, int col, int matriz[lin][col]);
void atualizar_mundo (int lin, int col, int ini, int vizinhanca[lin][col], char **mundo);
void modelo_Neumann (char **mundo, int lin, int col, int ger); 
void modelo_Moore (char **mundo, int lin, int col, int ger); //explicacao maior no final

void msleep(long msec){
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}

int main () {

    int n_line = 0, n_cols = 0, geracoes = 0, y, x;
    char modelo;

    scanf ("%i %i", &n_line, &n_cols);
    scanf ("%i", &geracoes);
    scanf (" %c", &modelo);
    getchar();
    if (n_cols <= 0 || n_line <= 0 || geracoes <= 0 || modelo < 'M' || modelo > 'N'){
        printf ("Dados de entrada apresentam erro.\n");
        return 0;
    }

    char **mundo = malloc (n_line * sizeof(void *));
    for (y = 0; y < n_line; y++)
    {
        mundo[y] = (char *) malloc ((n_cols + 1) * sizeof (char *)); 
        for (x = 0; x <= n_cols; x++)
        {
            scanf ("%c", (mundo[y] + x));
        }       
    }
     
    if (modelo == 'M')
        modelo_Moore(mundo, n_line, n_cols, geracoes);
     else 
        modelo_Neumann(mundo, n_line, n_cols, geracoes);

    // for (y = 0; y < n_line; y++)
    // {
    //     for (x = 0; x <= n_cols; x++)
    //     {
    //         printf ("%c", *(mundo[y] + x));
    //     }        
    // }

    for (y = 0; y < n_line; y++)
    {
        free (mundo[y]);   
    }
    free (mundo);
    return 0;
}

void modelo_Neumann (char **mundo, int lin, int col, int ger){

    //matriz com 4 lin e 4 col a mais para nao ficar tratando posicoes onde a vizinhaca sera no outro extremo
    int vizinhanca[lin + 4][col + 4];
        
    //adicionando a quantidade de vizinhos 'vivos' q cada celula possui
    for (int geracao = 0; geracao < ger; geracao++)
    {
        system ("clear");
        reiniciar_vizinhanca (lin + 4, col + 4, vizinhanca);
        for (int linha_atual = 2; linha_atual < lin + 2; linha_atual++)
        {
            for (int col_atual = 2; col_atual < col + 2; col_atual++)
            {           
                if (mundo[linha_atual - 2][col_atual - 2] == 'x'){
                    vizinhanca[linha_atual + 1][col_atual] += 1;
                    vizinhanca[linha_atual + 2][col_atual] += 1;
                    vizinhanca[linha_atual - 1][col_atual] += 1;
                    vizinhanca[linha_atual - 2][col_atual] += 1;
                    vizinhanca[linha_atual][col_atual + 1] += 1;
                    vizinhanca[linha_atual][col_atual + 2] += 1;
                    vizinhanca[linha_atual][col_atual - 1] += 1;
                    vizinhanca[linha_atual][col_atual - 2] += 1;
                }
            }      
        }
        
        //atribuindo os valores do 'excesso' da matriz as suas posicoes originais (*superior e* inferior)
        for (int col_atual = 2; col_atual < col + 2; col_atual++){                  
            vizinhanca[lin][col_atual] += vizinhanca[0][col_atual];  
            vizinhanca[lin + 1][col_atual] += vizinhanca[1][col_atual]; 
            vizinhanca[2][col_atual] += vizinhanca[lin + 2][col_atual];  
            vizinhanca[3][col_atual] += vizinhanca[lin + 3][col_atual];         
        }
        // (direito e esquerdo)
        for (int linha_atual = 2; linha_atual < lin + 2; linha_atual++){                  
            vizinhanca[linha_atual][2] += vizinhanca[linha_atual][col + 2];  
            vizinhanca[linha_atual][3] += vizinhanca[linha_atual][col + 3];
            vizinhanca[linha_atual][col + 1] += vizinhanca[linha_atual][1];  
            vizinhanca[linha_atual][col] += vizinhanca[linha_atual][0];          
        }

        //atualizando mundo
        atualizar_mundo (lin + 2, col + 2, 2, vizinhanca, mundo);
        for (int y = 0; y < lin; y++) {
            for (int x = 0; x <= col; x++) {
                printf ("%c", *(mundo[y] + x));
            }        
        }
        msleep(500);
    }
}

void modelo_Moore (char **mundo, int lin, int col, int ger){

    //matriz com 2 lin e 2 col a mais para nao ficar tratando posicoes onde a vizinhaca sera no outro extremo
    int vizinhanca[lin + 2][col + 2];

    for (int geracao = 0; geracao < ger; geracao++)
    {
        system ("clear");
         //adicionando a quantidade de vizinhos 'vivos' que cada celula possui
        reiniciar_vizinhanca (lin + 2, col + 2, vizinhanca);
        for (int linha_atual = 1; linha_atual < lin + 1; linha_atual++)
        {
            for (int col_atual = 1; col_atual < col + 1; col_atual++)
            {           
                if (mundo[linha_atual - 1][col_atual - 1] == 'x'){
                    vizinhanca[linha_atual - 1][col_atual - 1] += 1;
                    vizinhanca[linha_atual - 1][col_atual] += 1;
                    vizinhanca[linha_atual - 1][col_atual + 1] += 1;
                    vizinhanca[linha_atual][col_atual - 1] += 1;
                    vizinhanca[linha_atual][col_atual + 1] += 1;
                    vizinhanca[linha_atual + 1][col_atual + 1] += 1;
                    vizinhanca[linha_atual + 1][col_atual] += 1;
                    vizinhanca[linha_atual + 1][col_atual - 1] += 1;
                }
            }     
        }

        //atribuindo os valores do 'excesso' da matriz as suas posicoes originais (superior e inferior)
        for (int col_atual = 1; col_atual < col + 1; col_atual++){                  
            vizinhanca[lin][col_atual] += vizinhanca[0][col_atual];
            vizinhanca[1][col_atual] += vizinhanca[lin + 1][col_atual];         
        }
        // (direito e esquerdo)
        for (int linha_atual = 1; linha_atual < lin + 1; linha_atual++){                  
            vizinhanca[linha_atual][1] += vizinhanca[linha_atual][col + 1];  
            vizinhanca[linha_atual][col] += vizinhanca[linha_atual][0];          
        }
        //diagonais
        troca (vizinhanca, 0, 0, lin, col);
        troca (vizinhanca, 0, col + 1, lin, 1);
        troca (vizinhanca, lin + 1, 0, 1, col);
        troca (vizinhanca, lin + 1, col + 1, 1, 1);
        
        //atualizando mundo
        atualizar_mundo (lin + 1, col + 1, 1, vizinhanca, mundo);

        for (int y = 0; y < lin; y++) {
            for (int x = 0; x <= col; x++) {
                printf ("%c", *(mundo[y] + x));
            }        
        }
        msleep (500);
    }
}

void atualizar_mundo (int lin, int col, int ini, int vizinhanca[lin + ini][col + ini], char **mundo){
    for (int linha_atual = ini; linha_atual < lin; linha_atual++)
    {
        for (int col_atual = ini; col_atual < col; col_atual++)
        {           
            if (mundo[linha_atual - ini][col_atual - ini] == 'x'){
                if (vizinhanca[linha_atual][col_atual] > 3 || vizinhanca[linha_atual][col_atual] < 2)
                    mundo[linha_atual - ini][col_atual - ini] = '.';
            } else {
                if (vizinhanca[linha_atual][col_atual] == 3)
                    mundo[linha_atual - ini][col_atual - ini] = 'x';
            }
        }        
    }
}

void reiniciar_vizinhanca(int lin, int col, int matriz[lin][col]){

    for (int y = 0; y < lin; y++)
    {
        for (int x = 0; x < col; x++)
        {           
            matriz[y][x] = 0;
        }        
    }

}


/*
Exemplo do modelo:
lin = 8, col = 8, M
1:|.|.|.|.|.|.|.|.|\n|
0:|x|.|.|.|.|.|.|.|\n|
2:|.|.|.|.|.|.|.|.|\n|
3:|.|.|.|x|x|x|.|.|\n|
4:|.|.|.|x|x|.|.|.|\n|
5:|.|.|.|.|.|.|.|.|\n|
6:|.|.|.|.|.|.|.|.|\n|


vizinhanca (geracao 1):
linha = lin + 2, coluna = col + 2

0:|1  |1|1|0|0|0|0|0|0|   0|

1:|1  | |1| | | | | | |   0|
2:|1  |1|1| | | | | | |   0|
3:|   | | |1|2|3|2| | |   0|
4:|   | | |2|3|4|2|1| |   0|
5:|   | | |2|3|4|3|1| |   0|
6:|   | | |1|2|2|1| | |   0|
7:|   | | | | | | | | |   0|

8:|0  |0|0|0|0|0|0|0|0|   0|

Fazer as trocas -> 7: += 0:; 1: += 8:; ...

*/