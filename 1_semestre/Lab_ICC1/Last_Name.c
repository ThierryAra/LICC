#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *receive_strings (int *stop);
char *capture_last_name (char *name);

int main () {
    char *last_name = NULL;
    int stop = 0, i;
    
    char **names = (char **) malloc (1 * sizeof(void *));
    for (i = 1; stop == 0; i++) {
        names = (char **)realloc (names, i * sizeof(char *));
        names[i - 1] = receive_strings(&stop);
    }
    
    for (int j = 0; j <= (i - 3); j += 2) {
        last_name = capture_last_name(names[j]);
        names[j + 1] = strcat (names[j + 1], last_name);
        free (last_name);
    }

    for (int j = 0; j < i - 1; j++) printf ("%s\n", names[j]);
    for ( int j = 0; j < i - 1; j++) free (names[j]); 
    free (names);
    
    return 0;
}

char *receive_strings (int *stop) {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n' && input != '$') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    if (input == '$')
        *stop = 1;

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}

char *capture_last_name (char *name){
    char *last_name = NULL, c;
    int j = 1, i, size_last_name = 0;

    // Scrolling the name backwards to get the last last_name faster
    for (i = strlen(name); name[i - 1] != ' '; i--, j++) {
        last_name = realloc(last_name, j * sizeof(char *));
        last_name[j - 1] = name[i - 1];
        size_last_name++;
    }
    last_name = realloc(last_name, (j + 1) * sizeof(char *));
    last_name[j - 1] = ' '; // Space after the last letter
    last_name[j] = '\0';

    // Inverting the last name
    for (int i = 0; i < (int)((size_last_name+1)/2); i++) {
        c = last_name[i];
        last_name[i] = last_name[size_last_name - i];
        last_name[size_last_name - i] = c;
    }

    return last_name;
}