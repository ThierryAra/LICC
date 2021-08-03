#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define EXCHANGE(matrix, yo, xo, y, x) ({int c = matrix[y][x]; matrix[y][x] += matrix[yo][xo];  matrix[yo][xo] += c;})

void restart_neighborhood(int lin, int col, int matrix[lin][col]);
void update_world (int lin, int col, int ini, int neighborhood[lin][col], char **world);
void model_neumann (char **world, int lin, int col, int generation); 
void model_moore (char **world, int lin, int col, int generation); //explicacao maior no final

int main () {

    int n_line = 0, n_cols = 0, generations = 0, y, x;
    char model;

    scanf ("%i %i", &n_line, &n_cols);
    scanf ("%i", &generations);
    scanf (" %c", &model);
    getchar();
    if (n_cols <= 0 || n_line <= 0 || generations <= 0 || model < 'M' || model > 'N'){
        printf ("Dados de entrada apresentam erro.\n"); // Input data have error.
        return 0;
    }

    char **world = malloc (n_line * sizeof(void *));
    for (y = 0; y < n_line; y++)
    {
        world[y] = (char *) malloc ((n_cols + 1) * sizeof (char *)); 
        for (x = 0; x <= n_cols; x++)
        {
            scanf ("%c", (world[y] + x));
        }       
    }
     
    if (model == 'M')
        model_moore(world, n_line, n_cols, generations);
     else 
        model_neumann(world, n_line, n_cols, generations);

    for (y = 0; y < n_line; y++)
    {
        free (world[y]);   
    }
    free (world);
    return 0;
}

void model_neumann (char **world, int lin, int col, int generation){

    // Matrix whith 4 lin and 4 col more so as not to treat positions where the neighborhood is at the other extreme
    int neighborhood[lin + 4][col + 4];
        
    // Adding the number of 'living' neighbors that each cell has
    for (int generation = 0; generation < generation; generation++)
    {
        restart_neighborhood (lin + 4, col + 4, neighborhood);
        for (int current_line = 2; current_line < lin + 2; current_line++)
        {
            for (int current_col = 2; current_col < col + 2; current_col++)
            {           
                if (world[current_line - 2][current_col - 2] == 'x'){
                    neighborhood[current_line + 1][current_col] += 1;
                    neighborhood[current_line + 2][current_col] += 1;
                    neighborhood[current_line - 1][current_col] += 1;
                    neighborhood[current_line - 2][current_col] += 1;
                    neighborhood[current_line][current_col + 1] += 1;
                    neighborhood[current_line][current_col + 2] += 1;
                    neighborhood[current_line][current_col - 1] += 1;
                    neighborhood[current_line][current_col - 2] += 1;
                }
            }      
        }
        
        // Assingning the matrix's 'excess' values to their original positions (top and bottom)        
        for (int current_col = 2; current_col < col + 2; current_col++){                  
            neighborhood[lin][current_col] += neighborhood[0][current_col];  
            neighborhood[lin + 1][current_col] += neighborhood[1][current_col]; 
            neighborhood[2][current_col] += neighborhood[lin + 2][current_col];  
            neighborhood[3][current_col] += neighborhood[lin + 3][current_col];         
        }
        // (right and left)
        for (int current_line = 2; current_line < lin + 2; current_line++){                  
            neighborhood[current_line][2] += neighborhood[current_line][col + 2];  
            neighborhood[current_line][3] += neighborhood[current_line][col + 3];
            neighborhood[current_line][col + 1] += neighborhood[current_line][1];  
            neighborhood[current_line][col] += neighborhood[current_line][0];          
        }

        //update world
        update_world (lin + 2, col + 2, 2, neighborhood, world);
        for (int y = 0; y < lin; y++) {
            for (int x = 0; x <= col; x++) {
                printf ("%c", *(world[y] + x));
            }        
        }
    }
}

void model_moore (char **world, int lin, int col, int generation){

    // Matrix whith 2 lin and 2 col more so as not to treat positions where the neighborhood is at the other extreme
    int neighborhood[lin + 2][col + 2];

    for (int generation = 0; generation < generation; generation++)
    {
        // Adding the number of 'living' neighbors that each cell has
        restart_neighborhood (lin + 2, col + 2, neighborhood);
        for (int current_line = 1; current_line < lin + 1; current_line++)
        {
            for (int current_col = 1; current_col < col + 1; current_col++)
            {           
                if (world[current_line - 1][current_col - 1] == 'x'){
                    neighborhood[current_line - 1][current_col - 1] += 1;
                    neighborhood[current_line - 1][current_col] += 1;
                    neighborhood[current_line - 1][current_col + 1] += 1;
                    neighborhood[current_line][current_col - 1] += 1;
                    neighborhood[current_line][current_col + 1] += 1;
                    neighborhood[current_line + 1][current_col + 1] += 1;
                    neighborhood[current_line + 1][current_col] += 1;
                    neighborhood[current_line + 1][current_col - 1] += 1;
                }
            }     
        }

        // Assingning the matrix's 'excess' values to their original positions (top and bottom) 
        for (int current_col = 1; current_col < col + 1; current_col++){                  
            neighborhood[lin][current_col] += neighborhood[0][current_col];
            neighborhood[1][current_col] += neighborhood[lin + 1][current_col];         
        }
        // (right and left)
        for (int current_line = 1; current_line < lin + 1; current_line++){                  
            neighborhood[current_line][1] += neighborhood[current_line][col + 1];  
            neighborhood[current_line][col] += neighborhood[current_line][0];          
        }
        // (diagonals)
        EXCHANGE (neighborhood, 0, 0, lin, col);
        EXCHANGE (neighborhood, 0, col + 1, lin, 1);
        EXCHANGE (neighborhood, lin + 1, 0, 1, col);
        EXCHANGE (neighborhood, lin + 1, col + 1, 1, 1);
        
        update_world (lin + 1, col + 1, 1, neighborhood, world);

        for (int y = 0; y < lin; y++) {
            for (int x = 0; x <= col; x++) {
                printf ("%c", *(world[y] + x));
            }        
        }
    }
}

void update_world (int lin, int col, int ini, int neighborhood[lin + ini][col + ini], char **world){
    for (int current_line = ini; current_line < lin; current_line++)
    {
        for (int current_col = ini; current_col < col; current_col++)
        {           
            if (world[current_line - ini][current_col - ini] == 'x'){
                if (neighborhood[current_line][current_col] > 3 || neighborhood[current_line][current_col] < 2)
                    world[current_line - ini][current_col - ini] = '.';
            } else {
                if (neighborhood[current_line][current_col] == 3)
                    world[current_line - ini][current_col - ini] = 'x';
            }
        }        
    }
}

void restart_neighborhood(int lin, int col, int matrix[lin][col]){

    for (int y = 0; y < lin; y++)
    {
        for (int x = 0; x < col; x++)
        {           
            matrix[y][x] = 0;
        }        
    }

}


/*
Model example:
lin = 8, col = 8, M
1:|.|.|.|.|.|.|.|.|\n|
0:|x|.|.|.|.|.|.|.|\n|
2:|.|.|.|.|.|.|.|.|\n|
3:|.|.|.|x|x|x|.|.|\n|
4:|.|.|.|x|x|.|.|.|\n|
5:|.|.|.|.|.|.|.|.|\n|
6:|.|.|.|.|.|.|.|.|\n|


neighborhood (generation 1):
line = lin + 2, column = col + 2

0:|1  |1|1|0|0|0|0|0|0|   0|

1:|1  | |1| | | | | | |   0|
2:|1  |1|1| | | | | | |   0|
3:|   | | |1|2|3|2| | |   0|
4:|   | | |2|3|4|2|1| |   0|
5:|   | | |2|3|4|3|1| |   0|
6:|   | | |1|2|2|1| | |   0|
7:|   | | | | | | | | |   0|

8:|0  |0|0|0|0|0|0|0|0|   0|

Make the exchanges -> 7: += 0:; 1: += 8:; ...

*/