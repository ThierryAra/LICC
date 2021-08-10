#include<stdio.h>

int main () {

    char matrix[3][6];
    int line, column, game = 0;

    // Filling the matrix
    for (line = 0; line < 3; line++)
    {
        for (column = 0; column < 6; column++)
        {
            scanf ("%c", &matrix[line][column]);
            if (matrix[line][column] == '-'){
                game++;
            }
        }
    }

    line = 0, column = 0;

    while (line < 3)
    {
        if (matrix[line][0] ==  matrix[line][2] && matrix[line][0] == matrix[line][4]){
            if (matrix[line][0] == 'x'){
                printf ("x ganhou");
                return 0;
            } else if (matrix[line][0] == 'o') {
                printf ("o ganhou");
                return 0;
            }
        // 3 in column
        } else if (matrix[0][column] ==  matrix[1][column] && matrix[0][column] == matrix[2][column]){
            if (matrix[0][line] == 'x'){
                printf ("x ganhou");
                return 0;
            } else if (matrix[0][line] == 'o') {
                printf ("o ganhou");
                return 0;
            }
        }
        line++;
        column += 2;
    }

    // 3 na diagonal primary
    if (matrix[0][0] ==  matrix[1][2] && matrix[0][0] == matrix[2][3]){
        if (matrix[line][column] == 'x'){
            printf ("x ganhou");
            return 0;
        } else if (matrix[line][column] == 'o') {
            printf ("o ganhou");
            return 0;
        }
    // 3 na secondary diagonal
    } else if (matrix[0][4] ==  matrix[1][2] && matrix[0][4] == matrix[2][0]){
        if (matrix[0][4] == 'x'){
            printf ("x ganhou");
            return 0;
        } else if (matrix[0][4] == 'o') {
            printf ("o ganhou");
            return 0;
        }
    }  else if (game != 0){
        printf ("em game");
    } else {
        printf ("empate");
    }

    return 0;
}