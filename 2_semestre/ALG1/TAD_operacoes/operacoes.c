#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "editar_conjunto.h"

sint *uniao(sint *conjunto1, sint *conjunto2){
    if(conjunto1 == NULL || conjunto2 == NULL)
        return NULL;

    sint *conjunto3 = malloc (N * sizeof(sint));

    for(sint i = 0; i < N; i++){
        if (conjunto1[i] == 1 || conjunto2[i] == 1)
            conjunto3[i] = 1;
        else
            conjunto3[i] = 0;
    }
    return conjunto3;
}

sint *interseccao(sint *conjunto1, sint *conjunto2){
    if(conjunto1 == NULL || conjunto2 == NULL)
        return NULL;

    sint *conjunto3 = malloc (N * sizeof(sint));

    for(sint i = 0; i < N; i++){
        if (conjunto1[i] == 1 && conjunto2[i] == 1)
            conjunto3[i] = 1;
        else
            conjunto3[i] = 0;
    }

    return conjunto3;
}

sint *diferenca(sint *conjunto1, sint *conjunto2){
    if(conjunto1 == NULL || conjunto2 == NULL)
        return NULL;

    sint *conjunto3 = malloc (N * sizeof(sint));

    for(sint i = 0; i < N; i++){
        if (conjunto1[i] == 1){
            if (conjunto2[i] == 1)
                conjunto3[i] = 0;
            else 
                conjunto3[i] = 1;
        }
        else
            conjunto3[i] = 0;
    }

    return conjunto3;
}

sint max_valor(sint *conjunto){
    if(conjunto == NULL)
        return 0;

    for (sint i = N - 1; i > 0; i--)
        if (conjunto[i] == 1)
            return i;
}

sint min_valor(sint *conjunto){
    if(conjunto == NULL)
        return 0;

    for (sint i = 0; i < N; i++)
        if (conjunto[i] == 1)
            return i;
}

sint verificar_igualdade(sint *conjunto1, sint *conjunto2){
    if(conjunto1 == NULL || conjunto2 == NULL)
        return 0;

    for(sint i = 0; i < N; i++)
        if (conjunto1[i] != conjunto2[i])
            return -1;
        
    return 1;
}