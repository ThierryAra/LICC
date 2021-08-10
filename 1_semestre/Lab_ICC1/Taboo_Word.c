#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main () {

    char taboo[20], *string = NULL, character;
    int amount_appearances = 0;

    scanf ("%s", taboo);
    getchar();

    int i = 0, k = 0;
    do {
        i++;
        character = getchar();
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = character;

        if (character == taboo[k]){
            k++;
            if (k == strlen(taboo)){
                amount_appearances++;
                // Removing the taboo word
                int new_position = (i - strlen(taboo) + 1);
                string = (char*)realloc(string, (new_position) * sizeof(char *));
                i = new_position - 1;
                k = 0;
            }
        } else {
            k = 0;
        }

    } while (character != '$');
    
    *(string + (i - 1)) = '\0';
    printf ("A palavra taboo foi encontrada %i vezes\n", amount_appearances);
    printf ("Frase: %s\n", string);

    free(string);
    return 0;
}