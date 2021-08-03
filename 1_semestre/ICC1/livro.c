#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *read_line ();

int main() {

    int n_lines, number_valid_positions;

    scanf ("%i", &n_lines);
    getchar();

    char *string[n_lines]; 
    for (int i = 0; i < n_lines; i++)
    {
        string[i] = read_line();
    }
 
    scanf (" %i", &number_valid_positions);
    int *valid_position = calloc (number_valid_positions, sizeof(int));
    int *aux = valid_position;
    
    // Indicates which lines will be displayed
    for (int i = 0; i < number_valid_positions; i++)
    {
        scanf (" %d", valid_position + i);
    }

    // Display when on a line that should be displayed
    for (int i = 0; i < n_lines; i++)
    {
        for (int j = 0; j < number_valid_positions && j <= i; j++)
        {
            if (*(valid_position + j) == i)
                printf ("%s\n", string[i]);
        }
        
    }
    
    for (int j = 0; j < n_lines; j++)
		free(string[j]);
	  
  free (aux);
  
  return 0;
}

char *read_line () {
    char input;
    char *string = NULL;
    int i = 1;

    while ((input = getchar()) != '\n') {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = input;
        i++;
    }

    //adicionando '\0' ao final da string
    string = (char *) realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}
