#include<stdio.h>
#define WIDTH 65
#define HEIGHT 32
// Change two positions of the matrix
#define EXCHANGE(matrix, yo, xo, y, x) ({char c = matrix[y][x]; matrix[y][x] = matrix[yo][xo];  matrix[yo][xo] = c;})
// If the field is water(~) or air(' '), returns 1 and allows the exchange
#define CASE_SAND(matrix, y, x) ((matrix[y][x] == '~') || (matrix[y][x] == ' '))
// If the field is ar(' '), returns 1 and allows the exchange
#define CASE_WATER(matrix, y, x) ((matrix[y][x] == ' '))

void copy_matrix (char matrix[HEIGHT][WIDTH], char matrix_copied[HEIGHT][WIDTH]);

void change_physics (char matrix[HEIGHT][WIDTH], char matrix_copy[HEIGHT][WIDTH]);

void print_matrix (char matrix[HEIGHT][WIDTH]);

void initialize_simulator (char matrix[HEIGHT][WIDTH]);

int main () {

    int n_frames, frame, x, y;
    char new_particle, simulator[HEIGHT][WIDTH], simulator_copy[HEIGHT][WIDTH];
    initialize_simulator(simulator);

    scanf("%d", &n_frames);

    int count = 0;
    system ("clear && echo \"\033[1,1H\"");
    while (count < n_frames) {

        int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &new_particle);
        if (n_lido == EOF) 
            frame = n_frames;

        // Modifies all frames until it reaches the data in the scanf
        while (count < frame) {
            printf("frame: %d\n", count + 1);
            print_matrix(simulator);
            change_physics(simulator, simulator_copy);
            system ("echo \"\033[1;1H\" && sleep .150"); 
            copy_matrix(simulator, simulator_copy);
            count++;
        }

        // If there is a particle to be created, create it
        if (n_lido != EOF) {
            simulator[y][x] = new_particle;
        }
    }

    return 0;
}

void copy_matrix (char matrix[HEIGHT][WIDTH], char matrix_copied[HEIGHT][WIDTH]){
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            matrix[y][x] = matrix_copied[y][x];
        }
    }
}

void change_physics (char matrix[HEIGHT][WIDTH], char matrix_copy[HEIGHT][WIDTH]) {

    copy_matrix(matrix_copy, matrix);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (matrix[y][x])
            {
                // If it is sand (direction)
                case '#':
                    if ((y + 1) < HEIGHT){
                        // v
                        if (CASE_SAND(matrix, y + 1, x)){
                                EXCHANGE (matrix_copy, y, x, y + 1, x);
                        
                        // v + <
                        } else if (CASE_SAND(matrix, y + 1, x - 1)){
                            if ((x - 1) >= 0)
                                EXCHANGE (matrix_copy, y, x, y + 1, x - 1);
                        
                        // v + >
                        } else if (CASE_SAND(matrix, y + 1, x + 1)){
                            if ((x + 1) < 64)
                                EXCHANGE (matrix_copy, y, x, y + 1, x + 1);
                        }
                    }
                    break;
                // If it is water: (direction)
                case '~':
                    // v
                    if (CASE_WATER(matrix, y + 1, x) && ((y + 1) < HEIGHT))
                        EXCHANGE (matrix_copy, y, x, y + 1, x);
                    
                    // v + <
                    else if (CASE_WATER(matrix, y + 1, x - 1) && ((y + 1) < HEIGHT)){
                        if ((x - 1) >= 0)
                            EXCHANGE (matrix_copy, y, x, y + 1, x - 1);
                    
                    // v + >
                    } else if (CASE_WATER(matrix, y + 1, x + 1) && ((y + 1) < HEIGHT)){
                        if ((x + 1) < 64)
                            EXCHANGE (matrix_copy, y, x, y + 1, x + 1);
                    }
                    // <
                    else if (CASE_WATER(matrix, y, x - 1)){
                            if ((x - 1) >= 0)
                                EXCHANGE (matrix_copy, y, x, y, x - 1);
                    
                    // >
                    } else if (CASE_WATER(matrix, y, x + 1)){
                            if ((x + 1) < 64)
                                EXCHANGE (matrix_copy, y, x, y, x + 1);
                    }
                    break;
                // If it is air or stone, nothing should be done
                case ' ':
                    break;
                case '@':
                    break;
            }
                    
        }
    }
}

void print_matrix (char matrix[HEIGHT][WIDTH]){

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf ("%c", matrix[y][x]);
        }
    }

}

void initialize_simulator (char matrix[HEIGHT][WIDTH]){
    int y, x;

   for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < (WIDTH - 1); x++) matrix[y][x] = ' ';
        matrix[y][x] = '\n';
    } 
}

/* 
TEST CASE: 

20
0: 34 14 #
0: 35 14 #
0: 36 14 #
0: 37 14 #
0: 34 15 #
0: 20 16 #
0: 21 16 #
0: 22 16 #
0: 23 16 #
0: 30 16 #
0: 33 16 #
0: 34 16 #
0: 35 16 #
0: 38 16 #
0: 48 16 #
0: 49 16 #
0: 50 16 #
0: 51 16 #
0: 20 17 #
0: 29 17 #
0: 30 17 #
0: 31 17 #
0: 33 17 #
0: 34 17 #
0: 35 17 #
0: 37 17 #
0: 38 17 #
0: 39 17 #
0: 48 17 #
0: 16 18 #
0: 19 18 #
0: 20 18 #
0: 21 18 #
0: 24 18 #
0: 29 18 #
0: 30 18 #
0: 31 18 #
0: 36 18 #
0: 39 18 #
0: 44 18 #
0: 47 18 #
0: 48 18 #
0: 49 18 #
0: 52 18 #
0: 15 19 #
0: 16 19 #
0: 17 19 #
0: 18 19 #
0: 19 19 #
0: 20 19 #
0: 21 19 #
0: 22 19 #
0: 23 19 #
0: 24 19 #
0: 25 19 #
0: 30 19 #
0: 35 19 #
0: 38 19 #
0: 43 19 #
0: 44 19 #
0: 45 19 #
0: 46 19 #
0: 47 19 #
0: 48 19 #
0: 49 19 #
0: 50 19 #
0: 51 19 #
0: 52 19 #
0: 53 19 #
0: 15 20 #
0: 25 20 #
0: 30 20 #
0: 36 20 #
0: 38 20 #
0: 43 20 #
0: 50 20 #
0: 53 20 #
0: 16 21 #
0: 21 21 #
0: 24 21 #
0: 30 21 #
0: 38 21 #
0: 44 21 #
0: 49 21 #
0: 52 21 #
0: 17 22 #
0: 23 22 #
0: 24 22 #
0: 28 22 #
0: 30 22 #
0: 34 22 #
0: 36 22 #
0: 38 22 #
0: 40 22 #
0: 45 22 #
0: 51 22 #
0: 17 23 #
0: 23 23 #
0: 24 23 #
0: 25 23 #
0: 26 23 #
0: 27 23 #
0: 28 23 #
0: 29 23 #
0: 30 23 #
0: 31 23 #
0: 32 23 #
0: 33 23 #
0: 34 23 #
0: 35 23 #
0: 36 23 #
0: 37 23 #
0: 38 23 #
0: 39 23 #
0: 40 23 #
0: 41 23 #
0: 42 23 #
0: 43 23 #
0: 44 23 #
0: 45 23 #
0: 46 23 #
0: 47 23 #
0: 48 23 #
0: 51 23 #
0: 17 24 #
0: 23 24 #
0: 25 24 #
0: 30 24 #
0: 36 24 #
0: 43 24 #
0: 47 24 #
0: 50 24 #
0: 51 24 #
0: 17 25 #
0: 21 25 #
0: 23 25 #
0: 26 25 #
0: 32 25 #
0: 34 25 #
0: 38 25 #
0: 41 25 #
0: 47 25 #
0: 51 25 #
0: 17 26 #
0: 23 26 #
0: 25 26 #
0: 28 26 #
0: 31 26 #
0: 32 26 #
0: 33 26 #
0: 34 26 #
0: 35 26 #
0: 36 26 #
0: 37 26 #
0: 41 26 #
0: 47 26 #
0: 49 26 #
0: 51 26 #
0: 17 27 #
0: 23 27 #
0: 26 27 #
0: 30 27 #
0: 38 27 #
0: 43 27 #
0: 47 27 #
0: 51 27 #
0: 17 28 #
0: 23 28 #
0: 25 28 #
0: 30 28 #
0: 38 28 #
0: 40 28 #
0: 47 28 #
0: 49 28 #
0: 51 28 #
0: 14 29 #
0: 15 29 #
0: 17 29 #
0: 21 29 #
0: 23 29 #
0: 25 29 #
0: 27 29 #
0: 30 29 #
0: 38 29 #
0: 39 29 #
0: 42 29 #
0: 44 29 #
0: 47 29 #
0: 51 29 #
0: 5 30 #
0: 6 30 #
0: 7 30 #
0: 8 30 #
0: 9 30 #
0: 10 30 #
0: 11 30 #
0: 12 30 #
0: 13 30 ~
0: 14 30 ~
0: 15 30 ~
0: 16 30 ~
0: 17 30 #
0: 18 30 #
0: 19 30 #
0: 20 30 #
0: 21 30 #
0: 22 30 #
0: 23 30 #
0: 24 30 #
0: 25 30 #
0: 30 30 #
0: 36 30 #
0: 37 30 #
0: 38 30 #
0: 39 30 #
0: 40 30 #
0: 41 30 #
0: 42 30 #
0: 43 30 #
0: 44 30 ~
0: 45 30 ~
0: 46 30 ~
0: 47 30 ~
0: 48 30 #
0: 49 30 #
0: 50 30 #
0: 51 30 #
0: 52 30 #
0: 53 30 #
0: 0 31 #
0: 1 31 #
0: 2 31 #
0: 3 31 #
0: 4 31 #
0: 5 31 ~
0: 6 31 ~
0: 7 31 ~
0: 8 31 ~
0: 9 31 ~
0: 10 31 ~
0: 11 31 ~
0: 12 31 ~
0: 13 31 ~
0: 14 31 ~
0: 15 31 ~
0: 16 31 ~
0: 17 31 ~
0: 18 31 ~
0: 19 31 ~
0: 20 31 ~
0: 21 31 ~
0: 22 31 ~
0: 23 31 ~
0: 24 31 #
0: 25 31 #
0: 26 31 #
0: 27 31 #
0: 28 31 #
0: 29 31 #
0: 30 31 #
0: 31 31 #
0: 32 31 #
0: 33 31 #
0: 34 31 #
0: 35 31 #
0: 36 31 ~
0: 37 31 ~
0: 38 31 ~
0: 39 31 ~
0: 40 31 ~
0: 41 31 ~
0: 42 31 ~
0: 43 31 ~
0: 44 31 ~
0: 45 31 ~
0: 46 31 ~
0: 47 31 ~
0: 48 31 ~
0: 49 31 ~
0: 50 31 ~
0: 51 31 ~
0: 52 31 ~
0: 53 31 ~
0: 54 31 #
0: 55 31 #
0: 56 31 #
0: 57 31 #
0: 58 31 #
0: 59 31 #
0: 60 31 #
0: 61 31 #
0: 62 31 #

*/