#include<stdio.h>
#include<stdlib.h>

typedef struct status_pokemon {
    int hp, attack, defense, special_attack, special_defense, speed;
} Status;

typedef struct attack_pokemon {
    char name_attack[20];
    int base_power;
    float accuracy;
    char class;
} Attack;


typedef struct pokemon {
    char name_pokemon[50];
    char primary_type[20];
    char secondary_type[20];
    Status status;
    Attack attacks[4];
} Pokemon;

void register_pokemon (Pokemon *pokemon);
void register_attack (Attack *pokemon_attacks);
void print_pokemon (Pokemon *pokemon);
void print_attack (Attack *attack);

int main () {

    Pokemon *pokemon_list = NULL;
    int option, amount_pokemons = 0, index_attack, index_pokemon;

    scanf ("%i", &option);
    getchar();

    while (option != 0)
    {
        switch (option)
        {
        case 1: // Register pokemon
            amount_pokemons++;
            pokemon_list = realloc (pokemon_list, amount_pokemons * sizeof(Pokemon));
            register_pokemon (&pokemon_list[amount_pokemons - 1]);
            break;
        case 2: // Register a pokemon attack
            scanf (" %i", &index_pokemon);
            scanf (" %i", &index_attack);
            register_attack (&pokemon_list[index_pokemon].attacks[index_attack]);
            break;
        case 3: // Print 1 pokemon
            scanf (" %i", &index_pokemon);
            print_pokemon (&pokemon_list[index_pokemon]);
            break;
        case 4: // Print a attack pokemon
            scanf (" %i", &index_pokemon);
            scanf (" %i", &index_attack);
            print_attack (&pokemon_list[index_pokemon].attacks[index_attack]);
            break;
        
        default:
            break;
        }
    
    scanf ("%i", &option);
    getchar();
    }
     
    free (pokemon_list);
    return 0;
}

void register_pokemon (Pokemon *pokemon){
    scanf (" %s", pokemon->name_pokemon);
    scanf (" %s", pokemon->primary_type);
    scanf (" %s", pokemon->secondary_type);
    scanf (" %i", &pokemon->status.hp);
    scanf (" %i", &pokemon->status.attack);
    scanf (" %i", &pokemon->status.defense);
    scanf (" %i", &pokemon->status.special_attack);
    scanf (" %i", &pokemon->status.special_defense);
    scanf (" %i", &pokemon->status.speed);
}

void register_attack (Attack *pokemon_attacks){
    scanf (" %s", pokemon_attacks->name_attack);
    scanf (" %i", &pokemon_attacks->base_power);
    scanf (" %f", &pokemon_attacks->accuracy);
    scanf (" %c", &pokemon_attacks->class);
}

void print_pokemon (Pokemon *pokemon){
    printf ("Nome do Pokemon: %s\n", pokemon->name_pokemon);
    printf ("Tipo primario: %s\n", pokemon->primary_type);
    printf ("Tipo secundario: %s\n", pokemon->secondary_type);
    printf ("Status:\n");
    printf ("\tHP: %i\n", pokemon->status.hp);
    printf ("\tAtaque: %i\n", pokemon->status.attack);
    printf ("\tDefesa: %i\n", pokemon->status.defense);
    printf ("\tAtaque Especial: %i\n", pokemon->status.special_attack);
    printf ("\tDefesa Especial: %i\n", pokemon->status.special_defense);
    printf ("\tspeed: %i\n\n", pokemon->status.speed);
}

void print_attack (Attack *attack){
    printf ("Nome do ataque: %s\n", attack->name_attack);
    printf ("Poder base: %d\n", attack->base_power);
    printf ("Acuracia: %f\n", attack->accuracy);
    printf ("Classe: %c\n\n", attack->class);
}