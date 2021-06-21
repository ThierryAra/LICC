#include<stdio.h>

int main () {

    char mat[3][6];
    int i, j, jogo = 0;

    //preenchendo a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            scanf ("%c", &mat[i][j]);
            if (mat[i][j] == '-'){
                jogo++;
            }
        }
    }

    i = 0, j = 0;

    while (i < 3)
    {
        //3 na linha
        if (mat[i][0] ==  mat[i][2] && mat[i][0] == mat[i][4]){
            if (mat[i][0] == 'x'){
                printf ("x ganhou");
                return 0;
            } else if (mat[i][0] == 'o') {
                printf ("o ganhou");
                return 0;
            }
        //3 na coluna
        } else if (mat[0][j] ==  mat[1][j] && mat[0][j] == mat[2][j]){
            if (mat[0][i] == 'x'){
                printf ("x ganhou");
                return 0;
            } else if (mat[0][i] == 'o') {
                printf ("o ganhou");
                return 0;
            }
        }
        i++;
        j += 2;
    }

    //3 na diagonal primaria
    if (mat[0][0] ==  mat[1][2] && mat[0][0] == mat[2][3]){
        if (mat[i][j] == 'x'){
            printf ("x ganhou");
            return 0;
        } else if (mat[i][j] == 'o') {
            printf ("o ganhou");
            return 0;
        }
    //3 na diagonal secundaria
    } else if (mat[0][4] ==  mat[1][2] && mat[0][4] == mat[2][0]){
        if (mat[0][4] == 'x'){
            printf ("x ganhou");
            return 0;
        } else if (mat[0][4] == 'o') {
            printf ("o ganhou");
            return 0;
        }
    }  else if (jogo != 0){
        printf ("em jogo");
    } else {
        printf ("empate");
    }

    return 0;
}