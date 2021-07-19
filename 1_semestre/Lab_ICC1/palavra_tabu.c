#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main () {

    char tabu[20], *string = NULL, carct;
    int qtd_aparicoes = 0, i = 0, k = 0;

    scanf ("%s", tabu);
    getchar();

    do {
        i++;
        carct = getchar();
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = carct;

        if (carct == tabu[k]){
            k++;
            if (k == strlen(tabu)){
                qtd_aparicoes++;
                //removendo a palavra tabu
                int nova_posicao = (i - strlen(tabu) + 1);
                string = (char*)realloc(string, (nova_posicao) * sizeof(char *));
                i = nova_posicao - 1;
                k = 0;
            }
        } else {
            k = 0;
        }

    } while (carct != '$');
    
    *(string + (i - 1)) = '\0';
    printf ("A palavra tabu foi encontrada %i vezes\n", qtd_aparicoes);
    printf ("Frase: %s\n", string);

    free(string);
    return 0;
}