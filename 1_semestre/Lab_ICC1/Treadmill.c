// Treadmill_Plinio
#include<stdio.h>
#define LINE 32
#define COLUMN 65

void print_matrix (int v, char matrix[LINE][COLUMN]);
int main () {

    char matrix[LINE][COLUMN], previous;
    int start_column = 0, start_line = 0;

    // Assigns whitespace in the entire matrix
    for (int i = 0; i < LINE; i++){
        for (int j = 0; j < COLUMN; j++)
        {
            matrix[i][j] = 32;
        }
    }

    // Filling the matrix
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            scanf ("%c", &matrix[i][j]);
            if (matrix[i][j] == '['){
                start_line = i;
                start_column = j;
            }
            // If the matrix reads an enter it will descend a LINE
            if (matrix[i][j] == '\n'){
                break;
            }
        } 
    }

    // Keeps on transforming until you have read the whole matrix or not read a single point
    for (int i = start_line; i < LINE; i++)
    {
        for (int j = start_column; j < COLUMN; j++)
        {  
            if (matrix[i][j] == '.'){
                print_matrix(1, matrix);
                return 0;
            }

            if (matrix[i][j] == '>'){
                
                previous = '>';
                matrix[i][j] = '.';
                // Checks if the next position is empty
                if (matrix[i][j + 2] == ' ') {
                    print_matrix (-1, matrix);
                    return 0;
                }
                // Checks loop type ><
                if (matrix[i][j + 2] == '<'){
                    matrix[i][j + 2] = '.';
                    print_matrix(1, matrix);
                    return 0;
                }
                // Finishes if it finds ]
                if (matrix[i][j + 2] == ']'){
                    print_matrix(0, matrix);
                    return 0;
                }
                j++;

            } else if (matrix[i][j] == 'v'){
               
                previous = 'v';
                matrix[i][j] = '.';
                // Checks if the next position is empty
                if (matrix[i + 1][j] == ' ') {
                    print_matrix (-1, matrix);
                    return 0;
                }
                start_column = j;
                break;

            } else if (matrix[i][j] == '^'){

                previous = '^';
                matrix[i][j] = '.';
                // Checks if the next position is empty
                if (matrix[i - 1][j] == ' ') {
                    print_matrix (-1, matrix);
                    return 0;
                }
                i = i - 2;
                start_column = j;
                break;

            } else if (matrix[i][j] == '<'){
                
                previous = '<';
                matrix[i][j] = '.';
                // Checks if the next position is empty
                if (matrix[i][j - 2] == ' ') {
                    print_matrix (-1, matrix);
                    return 0;
                }
                j = j - 3;

            } else if (matrix[i][j] == '#'){

                if (previous == '>'){
                    j++;
                } else if (previous == '^'){
                    i = i - 2;
                    start_column = j;
                    break;
                } else if (previous == 'v'){
                    start_column = j;
                    break;
                } else if (previous == '<'){
                    j = j - 3;
                }
            }
        }
    }

    print_matrix(0, matrix);
    return 0;
}


void print_matrix (int v, char matrix[LINE][COLUMN]) {

    if (v == -1){
        printf ("Falha na esteira.\n");
    } else if (v == 0) {
        printf ("Ok.\n");
    }
    else {
        printf ("Loop infinito.\n");
    }
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN-1; j++)
        {
            printf ("%c", matrix[i][j]);
        }
        printf ("\n");
    }

}

/* 

TEST CASE:

INPUT:
[ > > > > > > > v                                               
                v                                               
        > > > > v > > > ]                                       
        ^       v                                               
        ^       v                                               
        ^ < < < <                                               
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                

OUTPUT:
Loop infinito.
[ . . . . . . . .                                               
                .                                               
        . . . . . > > > ]                                       
        .       .                                               
        .       .                                               
        . . . . .                                               
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                

 */