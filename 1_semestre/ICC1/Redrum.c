//THIERRY DE SOUZA ARAUJO
//12681094

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int palindromo (char *texto, int tamanho_str, int inicio_str);
char *receber_texto ();

int main () {

    char *texto = receber_texto();

    int tamanho_string = strlen (texto), inicio_str = 0;
    int tipo_palindromo = palindromo (texto, tamanho_string - 1, inicio_str);

    if ((tipo_palindromo % 2) != 0){
        printf ("Nao eh um palindromo\n");
    } else if (tipo_palindromo == 0){
        printf ("Palindromo direto\n");
    } else {
        printf ("Palindromo indireto\n");
    }

    free (texto);
    return 0;
}

int palindromo (char *texto, int fim, int inicio){
    int tipo_palindromo = 0;
    if (inicio != fim && inicio < fim){
        //ignora os demais caracteres
        if (!isalnum(texto[inicio]) && texto[inicio] != ' ' && texto[inicio] != '/')
            return (tipo_palindromo += palindromo(texto, fim, inicio + 1));
        if (!isalnum(texto[fim]) && texto[fim] != ' ' && texto[fim] != '/')
            return (tipo_palindromo += palindromo(texto, fim - 1, inicio));

        //verifica igualdade entre caracteres: (a,a), (A,a), (a,A)
        if ((texto[inicio] == texto[fim]) || (texto[inicio] == texto[fim] - 32) || (texto[inicio] - 32 == texto[fim])) {
            tipo_palindromo = tipo_palindromo + palindromo(texto, fim - 1, inicio + 1);
            return (tipo_palindromo);
          //caso texto[ini/fim] seja '/' ou ' ', verifica-se a igualdade com o proximo caractere
        } else if ((texto[inicio] != texto[fim])){ 
            if ((texto[fim] == '/' || texto[fim] == ' ')){
                return (tipo_palindromo += 2 + palindromo(texto, fim - 1, inicio));
            } else if (texto[inicio] == '/' || texto[inicio] == ' '){
                return (tipo_palindromo += 2 + palindromo(texto, fim, inicio + 1));
            } else //caso algum dos caracteres nao sejam igual, tipo_palindromo se torna impar e termina
                return (1);
        } 
    } return (0);
}

char *receber_texto () {
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

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}