#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct gerenciar_estudantes {
    unsigned short int idade;
    int identificador;
    char *nome;
    char *curso;
} Estudante;

char *receber_strings ();
void buscar_aluno_curso (Estudante *alunos, int identificador, int qtd_alunos, char *curso);
void printar_alunos (Estudante *alunos, int qtd_alunos);

int main (){

    int opcao, qtd_estudantes = 0, parar = 0, identificador;
    Estudante *lista_estudantes = malloc (1 * sizeof(Estudante));

    //recebendo todos os alunos
    while (parar == 0) {
        scanf ("%i", &identificador);
        getchar();
        if (identificador == -1) {
            parar = 1;
        } else {
            qtd_estudantes++;
            lista_estudantes = realloc (lista_estudantes, qtd_estudantes * sizeof(Estudante));
            lista_estudantes[qtd_estudantes - 1].identificador = identificador; 
            lista_estudantes[qtd_estudantes - 1].nome = receber_strings();
            lista_estudantes[qtd_estudantes - 1].curso = receber_strings();
            scanf ("%hu", &lista_estudantes[qtd_estudantes - 1].idade);
        }
    }

    char *curso = NULL;
    scanf ("%i", &opcao);
    while (opcao != -1) {
        getchar();
        switch (opcao) { 
        case 1:
            scanf ("%i", &identificador);
            buscar_aluno_curso (lista_estudantes, identificador, qtd_estudantes, " ");
            break;
        case 2:
            curso = receber_strings();
            buscar_aluno_curso (lista_estudantes, 0101, qtd_estudantes, curso);
            free (curso);
            break;
        case 3:
            printar_alunos (lista_estudantes, qtd_estudantes);
            break;
        }
        scanf ("%i", &opcao);
    }
    
    for (int i = 0; i < qtd_estudantes; i++){
        free (lista_estudantes[i].curso);
        free (lista_estudantes[i].nome);
    }
    free (lista_estudantes);
    return 0;
}

char *receber_strings () {
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

void buscar_aluno_curso (Estudante *alunos, int identificador, int qtd_alunos, char *curso){   
    for (int i = 0; i < qtd_alunos; i++)
    {
        if (alunos[i].identificador == identificador || strcmp(alunos[i].curso,curso) == 0){
            printf ("Nome: %s\n", alunos[i].nome);
            printf ("Curso: %s\n", alunos[i].curso);
            printf ("N USP: %i\n", alunos[i].identificador);
            printf ("IDADE: %hu\n\n", alunos[i].idade);
        }
    }
}

void printar_alunos (Estudante *alunos, int qtd_alunos){  
    for (int i = 0; i < qtd_alunos; i++)
    {
        printf ("Nome: %s\n", alunos[i].nome);
        printf ("Curso: %s\n", alunos[i].curso);
        printf ("N USP: %i\n", alunos[i].identificador);
        printf ("IDADE: %hu\n\n", alunos[i].idade);
    }
}