// Attack_and_types
#include<stdio.h>
#include<stdlib.h>

int main () {

    int dimension = 0, i = 0, j = 0, i_best_attack = 0, enemy = 0;
    float best_attack = 0.0;

    scanf ("%i", &dimension);

    //valores da table
    float **table = malloc (dimension * sizeof(float *));

    for (i = 0; i < dimension; i++)
    {
        table[i] = calloc (dimension, sizeof(float *));
        for (j = 0; j < dimension; j++)
        {
            scanf ("%f", (table[i] + j));
        }     
    }

    //attacks a serem comparados 
    int amount_attacks = 1;
    int *attacks = malloc (amount_attacks * sizeof(int *));
    while (1)
    {
        //armazena (dano_ataque, atacante) -> (j, j + 1)
        scanf ("%i", (attacks + (amount_attacks - 1)));
        if (attacks[amount_attacks - 1] != -1) {
            amount_attacks += 1;
            attacks = realloc (attacks, amount_attacks * sizeof(int *));
            scanf ("%i", (attacks + (amount_attacks - 1)));
        }
        else
            break;

        amount_attacks += 1;
        attacks = realloc (attacks, amount_attacks * sizeof(int *));
    }
    
    scanf ("%i", &enemy);

    //comparando o dano de cada ataque
    j = 0;
    while (j <= (amount_attacks - 3))
    {
        float current_attack = (attacks[j] * table[attacks[j+1]][enemy]);
        if ( current_attack > best_attack ){
            best_attack = current_attack;
            i_best_attack = attacks[j+1];
        }
        j += 2;
    }
    
    printf ("O melhor ataque possui indice %i e dano %.2f\n", i_best_attack, best_attack);
            // The best attack has index %i and damage %.2f

    for (j = 0; j < dimension; j++)
        free (table[j]);
    free(table);
    free(attacks);
    
    return 0;
}