#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void check_maze (char **maze, int x_current, int y_current, int x_end, int y_end, int *steps_taken, bool *stop);
char *receive_string ();

int main (){

    int height, width;
    int x_start, y_start;
    int x_end, y_end;
    int steps_taken = 0;
    bool stop = false;
    
    char *file_name;
    file_name = receive_string();
    FILE *file_maze = fopen (file_name, "r");

    fscanf (file_maze, "%d %d", &height, &width);
    fscanf (file_maze, "%d %d", &y_start, &x_start);
    fscanf (file_maze, "%d %d\n", &y_end, &x_end);

    char **maze = malloc (sizeof (void*) * height);
    for (int i = 0; i < height; i++) {
        maze[i] = malloc (sizeof (char) * (width + 1));
        for (int j = 0; j < width + 1; j++) {
            fscanf (file_maze, "%c", &maze[i][j]);
        }
    }
    fclose (file_maze);

    check_maze (maze, x_start, y_start, x_end, y_end, &steps_taken, &stop);

    printf ("Caminho final:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width + 1; j++) {
            printf ("%c", maze[i][j]);
        }
    }
    printf ("Passos percorridos: %d\n", steps_taken);

    for (int i = 0; i < height; i++)
        free (maze[i]);
    free (maze);
    free (file_name);
}

void check_maze (
    char **maze, 
    int x_current, int y_current, 
    int x_end, int y_end, 
    int *steps_taken,
    bool *stop
){

    if (maze[y_current][x_current] != '*'){    
        maze[y_current][x_current] = '*';
        (*steps_taken)++;
        if (x_current == x_end && y_current == y_end){
            (*stop) = true;
        } else {
            if (maze[y_current][x_current - 1] == '.' && (*stop) == false)
                check_maze (maze, x_current - 1, y_current, x_end, y_end, steps_taken, stop);
            if (maze[y_current + 1][x_current] == '.' && (*stop) == false)
                check_maze (maze, x_current, y_current + 1, x_end, y_end, steps_taken, stop);
            if (maze[y_current][x_current + 1] == '.' && (*stop) == false)
                check_maze (maze, x_current + 1, y_current, x_end, y_end, steps_taken, stop);
            if (maze[y_current - 1][x_current] == '.' && (*stop) == false)
                check_maze (maze, x_current, y_current - 1, x_end, y_end, steps_taken, stop);
        }
    }
    
}

char *receive_string () {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}


/*

CASE TEST:

INPUT:
caso2.in
(
10 10
1 1
8 8
##########
#.#.##...#
#....###.#
###.####.#
#....#.#.#
#.#.##.#.#
#.#......#
###.##.#.#
#...#..#.#
########## 
)

OUTPUT:
Caminho final:
##########
#*#.##...#
#***.###.#
###*####.#
#***.#.#.#
#*#*##.#.#
#*#******#
###*##*#*#
#***#**#*#
##########
Passos percorridos: 26

*/