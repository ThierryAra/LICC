#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *receber_strings (int *parar);
char *capturar_sobrenome (char *nome);

int main () {
    char *sobrenome = NULL;
    int parar = 0, i;
    
    char **nomes = (char **) malloc (1 * sizeof(void *));
    for (i = 1; parar == 0; i++)
    {
        nomes = (char **)realloc (nomes, i * sizeof(char *));
        nomes[i - 1] = receber_strings(&parar);
    }
    
    for (int j = 0; j <= (i - 3); j += 2)
    {
        //sobrenome = malloc (strlen(capturar_sobrenome(nomes[j])) * sizeof(char));
        sobrenome = capturar_sobrenome(nomes[j]);
        nomes[j + 1] = strcat (nomes[j + 1], sobrenome);
        free (sobrenome);
    }

    for (int j = 0; j < i - 1; j++){
        printf ("%s\n", nomes[j]);
    }

    for ( int j = 0; j < i - 1; j++)
    {
        free (nomes[j]);
    }
    
    free (nomes);
    
    return 0;
}

char *receber_strings (int *parar) {
    char entrada;
    char *string = NULL;
    int i = 1;

    entrada = getchar();
    while (entrada != '\n' && entrada != '$') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = entrada;
        i++;
        entrada = getchar();
    }
    //argumento para parar de ler
    if (entrada == '$')
        *parar = 1;

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}

char *capturar_sobrenome (char *nome){
    char *sobrenome = NULL, c;
    int j = 1, i, tam_sobrenome = 0;

    //percorrendo o nome de tras pra frente para pegar o ultimo sobrenome mais rapido
    for (i = strlen(nome); nome[i - 1] != ' '; i--, j++)
    {
        sobrenome = realloc(sobrenome, j * sizeof(char *));
        sobrenome[j - 1] = nome[i - 1];
        tam_sobrenome++;
    }
    sobrenome = realloc(sobrenome, (j + 1) * sizeof(char *));
    sobrenome[j - 1] = ' '; //espaco depois da ultima letra
    sobrenome[j] = '\0';

    //invertendo o sobrenome
    for (int i = 0; i < (int)((tam_sobrenome+1)/2); i++)
    {
        c = sobrenome[i];
        sobrenome[i] = sobrenome[tam_sobrenome - i];
        sobrenome[tam_sobrenome - i] = c;
    }

    return sobrenome;
}