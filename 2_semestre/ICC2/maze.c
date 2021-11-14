// USP SAO CARLOS
// THIERRY DE SOUZA ARAUJO - 12681094
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void receive_maze (char ***maze, int *available_paths, 
                  int *initial_x, int *initial_y);
void walk_in_the_maze (char **maze, int initial_y, int initial_x, bool *stop);
void calculate  (char **maze, int *people, int *paths_taken, 
                double *exploration, int available_paths);
void print_informations (char **maze, int people, int available_paths, 
                        int paths_taken, double exploration);
char *receive_strings();

// Criei de forma global para não precisar passar como parametro para todas as funcoes
int width = 0, height = 0;

int main () {

    char **maze;
    int people = 0, available_paths = 0, paths_taken = 0;
    double exploration;

    int initial_x, initial_y;
    receive_maze(&maze, &available_paths, &initial_x, &initial_y);

    bool stop = false;
    walk_in_the_maze(maze, initial_y, initial_x, &stop);

    calculate(maze, &people, &paths_taken, &exploration, available_paths);

    print_informations(maze, people, available_paths, paths_taken, exploration);

    for (int i = 0; i < height; i++)
        free (maze[i]);
    free (maze);

    return 0;
}

void receive_maze (
    char ***maze, 
    int *available_paths, 
    int *initial_x, int *initial_y
){
    char *file_name = receive_strings();
    FILE *file = fopen(file_name, "r");

    fscanf(file, " %d %d", &height, &width);
    fscanf(file, " %d %d ", initial_y, initial_x);

    int i, j;
    (*maze) = malloc (sizeof (char**) * height);
    for (i = 0; i < height; i++) {
        (*maze)[i] = malloc (sizeof (char*) * (width + 1));
        for (j = 0; j < width; j++) {
            fscanf(file, "%c", &(*maze)[i][j]);
            if ((*maze)[i][j] == '.') (*available_paths)++;
        }

        if (i < (height - 1)) // While not on the last line the '\n' is read
                fscanf (file, "%c", &(*maze)[i][j]);
        else 
            (*maze)[i] = realloc ((*maze)[i], sizeof (char) * width);
    }

    fclose(file);
    free(file_name);
}

void walk_in_the_maze (char **maze, int initial_y, int initial_x, bool *stop){

    if (maze[initial_y][initial_x] == '.'){
        maze[initial_y][initial_x] = '*';
        if ((initial_y > 0 && initial_y < height - 1) && (initial_x > 0 && initial_x < width - 1)){
            if ( ((initial_y - 1) >= 0) && maze[initial_y - 1][initial_x] == '.')
                if (*stop == false) walk_in_the_maze(maze, initial_y - 1, initial_x, stop);
            if ( ((initial_x + 1) < width) && maze[initial_y][initial_x + 1] == '.')
                if (*stop == false) walk_in_the_maze(maze, initial_y, initial_x + 1, stop);
            if ( ((initial_y + 1) < height) && maze[initial_y + 1][initial_x] == '.')
                if (*stop == false) walk_in_the_maze(maze, initial_y + 1, initial_x, stop);
            if ( ((initial_x - 1) >= 0) && maze[initial_y][initial_x - 1] == '.')
                if (*stop == false) walk_in_the_maze(maze, initial_y, initial_x - 1, stop);
        } else 
            (*stop) = true;
    }
}

// Calculates the 'people' (#), the 'paths_taken' (*) in the maze and the 'exploration'
// 'exploration' is the percentage of 'paths_taken' in relation to those that could be used
void calculate (
    char **maze, 
    int *people, 
    int *paths_taken, 
    double *exploration, int available_paths
){
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (maze[y][x]) {
                case '#':   (*people)++;
                            break;
                case '*':   (*paths_taken)++;
                            break;
            }
        }
    }
    *exploration = ((*paths_taken * 100) / available_paths);
}

void print_informations (
    char **maze, 
    int people, 
    int available_paths, 
    int paths_taken, 
    double exploration
){

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++)
            printf ("%c", maze[y][x]);
        printf ("\n");
    }
    
    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n", people);
    printf("----Numero total de caminhos validos:   %d\n", available_paths);
    printf("----Numero total de caminhos visitados: %d\n", paths_taken);
    printf("----Exploracao total do labirinto: %.1lf%%\n", exploration);
}

char *receive_strings () {

    char input;
    char *string = NULL;
    int i = 1;

    while ((input = getchar()) != EOF) {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = input;
        i++;
    }
    //Add '\0' at the end of string
    string = realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}