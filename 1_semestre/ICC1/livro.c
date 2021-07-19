#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *read_line () {
    char entrada;
    char *string = NULL;
    int i = 1;

    while ((entrada = getchar()) != '\n') {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = entrada;
        i++;
    }

    //adicionando '\0' ao final da string
    string = (char *) realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}

int main() {

    int n_linhas, num_pos_validas;

    scanf ("%i", &n_linhas);
    getchar();

    char *string[n_linhas]; 
    for (int i = 0; i < n_linhas; i++)
    {
        string[i] = read_line();
    }
 
    scanf (" %i", &num_pos_validas);
    int *pos_validas = calloc (num_pos_validas, sizeof(int));
    int *aux = pos_validas;
    
    //indica quais as linhas q serão printadas
    for (int i = 0; i < num_pos_validas; i++)
    {
        scanf (" %d", pos_validas + i);
    }

    //printa quando esta em uma linha q deve ser printada
    for (int i = 0; i < n_linhas; i++)
    {
        for (int j = 0; j < num_pos_validas && j <= i; j++)
        {
            if (*(pos_validas + j) == i)
                printf ("%s\n", string[i]);
        }
        
    }
    
    for (int j = 0; j < n_linhas; j++)
		free(string[j]);
	  
  free (aux);
  
  return 0;
}