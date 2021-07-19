#include<stdio.h>
#include<stdlib.h>

typedef struct status_pokemon {
    int hp, ataque, defesa, atq_especial, defesa_especial, velocidade;
} Status;

typedef struct ataque_pokemon {
    char nome_ataque[20];
    int poder_base;
    float acuracia;
    char classe;
} Ataque;


typedef struct pokemon {
    char nome_pokemon[50];
    char tipo_primario[20];
    char tipo_secundario[20];
    Status status;
    Ataque ataques[4];
} Pokemon;

void cadastrar_pokemon (Pokemon *pokemon);
void cadastrar_ataque (Ataque *pokemon_ataque);
void printar_pokemon (Pokemon *pokemon);
void printar_ataque (Ataque *ataque);

int main () {

    Pokemon *lista_pokemon = NULL;
    int opcao, qtd_pokemons = 0, indice_ataque, indice_pokemon;

    scanf ("%i", &opcao);
    getchar();

    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1: //cadastrar pokemon
            qtd_pokemons++;
            lista_pokemon = realloc (lista_pokemon, qtd_pokemons * sizeof(Pokemon));
            cadastrar_pokemon (&lista_pokemon[qtd_pokemons - 1]);
            break;
        case 2: //cadastrar ataque de 1 pokeon
            scanf (" %i", &indice_pokemon);
            scanf (" %i", &indice_ataque);
            cadastrar_ataque (&lista_pokemon[indice_pokemon].ataques[indice_ataque]);
            break;
        case 3: //printar 1 pokemon
            scanf (" %i", &indice_pokemon);
            printar_pokemon (&lista_pokemon[indice_pokemon]);
            break;
        case 4: //pritar atq de 1 pokemon
            scanf (" %i", &indice_pokemon);
            scanf (" %i", &indice_ataque);
            printar_ataque (&lista_pokemon[indice_pokemon].ataques[indice_ataque]);
            break;
        
        default:
            break;
        }
    
    scanf ("%i", &opcao);
    getchar();
    }
     
    free (lista_pokemon);
    return 0;
}

void cadastrar_pokemon (Pokemon *pokemon){
    scanf (" %s", pokemon->nome_pokemon);
    scanf (" %s", pokemon->tipo_primario);
    scanf (" %s", pokemon->tipo_secundario);
    scanf (" %i", &pokemon->status.hp);
    scanf (" %i", &pokemon->status.ataque);
    scanf (" %i", &pokemon->status.defesa);
    scanf (" %i", &pokemon->status.atq_especial);
    scanf (" %i", &pokemon->status.defesa_especial);
    scanf (" %i", &pokemon->status.velocidade);
}

void cadastrar_ataque (Ataque *pokemon_ataque){
    scanf (" %s", pokemon_ataque->nome_ataque);
    scanf (" %i", &pokemon_ataque->poder_base);
    scanf (" %f", &pokemon_ataque->acuracia);
    scanf (" %c", &pokemon_ataque->classe);
}

void printar_pokemon (Pokemon *pokemon){
    printf ("Nome do Pokemon: %s\n", pokemon->nome_pokemon);
    printf ("Tipo primario: %s\n", pokemon->tipo_primario);
    printf ("Tipo secundario: %s\n", pokemon->tipo_secundario);
    printf ("Status:\n");
    printf ("\tHP: %i\n", pokemon->status.hp);
    printf ("\tAtaque: %i\n", pokemon->status.ataque);
    printf ("\tDefesa: %i\n", pokemon->status.defesa);
    printf ("\tAtaque Especial: %i\n", pokemon->status.atq_especial);
    printf ("\tDefesa Especial: %i\n", pokemon->status.defesa_especial);
    printf ("\tVelocidade: %i\n\n", pokemon->status.velocidade);
}

void printar_ataque (Ataque *ataque){
    printf ("Nome do Ataque: %s\n", ataque->nome_ataque);
    printf ("Poder base: %d\n", ataque->poder_base);
    printf ("Acuracia: %f\n", ataque->acuracia);
    printf ("Classe: %c\n\n", ataque->classe);
}