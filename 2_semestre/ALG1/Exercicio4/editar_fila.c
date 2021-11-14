#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"editar_fila.h"

/* 
    int inicio.: primeiro da fila
    int fim....: ultimo da fila
    int total..: quantidade total de objetos na fila
    int tamanho: quantidade de realloc's na fila, para evitar mover a fila para tras
                 ao remover alguem
    PACIENTE pacientes: vetor que simula a fila
 */
struct fila{
    int inicio, fim, total, tamanho;
    PACIENTE* pacientes;
};

FILA* criar(){
    FILA *fila;

    fila = malloc(sizeof(FILA));
    if(fila == NULL)
        exit(1);

    (fila->pacientes) = malloc(sizeof(PACIENTE));
    if((fila->pacientes) == NULL)
        exit(1);

    fila->total   = 0;
    fila->inicio  = 0;
    fila->fim     = 0;
    fila->tamanho = 0;

    return fila;
}

PACIENTE* criar_paciente(){
    PACIENTE* paciente;

    (paciente) = malloc(sizeof(PACIENTE));
    if((paciente) == NULL)
        exit(1);

    paciente->nome       = NULL;
    paciente->idade      = 0;
    paciente->agravante  = 0;
    paciente->prioridade = 0;

    return paciente;
}


int is_empty(FILA *fila){
    if(fila == NULL)
        return -1;

    if (fila->total == 0)
        return 1;
    else
        return 0;
}

int is_full(FILA *fila){
    if(fila == NULL)
        return -1;

    if (fila->total == TAMFILA)
        return 1;
    else
        return 0;
}

void encontrar_prioridade(FILA* fila, PACIENTE* paciente){
    if(fila == NULL)
        exit(1);

    if(paciente->idade >= 60){
        if(paciente->agravante == 1)
            paciente->prioridade = 1;
        else
            paciente->prioridade = 3;
    } else {
        if(paciente->agravante == 1)
            paciente->prioridade = 2;
        else
            paciente->prioridade = 4;
    }
}

void reordenar_fila(FILA* fila, int* posicao, int prioridade){
     if(fila == NULL)
        exit(1);

    //caso o total de pessoas seja 1, quer dizer que so ha ele na espera
    if(fila->total == 1){
        (*posicao) = fila->inicio;
        return;
    }

    (*posicao) = fila->fim - 1;

    //se a prioridade for igual, o paciente novo deve obedecer a ordem de chegada
    if(prioridade == ((fila->pacientes))[(*posicao)].prioridade){
        (*posicao) += 1;
        return;
    }

    //enquanto a prioridade do paciente em questao for menor do que as do que estao na fila
    //quer dizer que ele deve passar na frente, ou seja, os pacientes vao sendo passados 1 posicao
    //a frente
    while (1){
        if(prioridade >= ((fila->pacientes))[(*posicao)].prioridade){
            (*posicao)++;
            break;
        }
        fila->pacientes[*posicao + 1] = fila->pacientes[*posicao];

        if((*posicao) == fila->inicio){
            (*posicao) = fila->inicio;
            break;
        }
        (*posicao)--;
    }

}

int insert(FILA* fila, PACIENTE* paciente){
    if(fila == NULL)
        exit(1);

    if(is_full(fila) == 1)
        return 0;

    (fila->total)++;
    (fila->tamanho)++;
    fila->pacientes = realloc(fila->pacientes, fila->tamanho * sizeof(PACIENTE));

    int posicao = 0;

    encontrar_prioridade(fila, paciente);

    reordenar_fila(fila, &posicao, paciente->prioridade);

    // transferindo da variavel paciente para a fila
    (fila->pacientes)[posicao] = (*paciente);

    fila->fim = (fila->fim + 1) % TAMFILA;

    return 1;
}

int remover(FILA* fila, PACIENTE* paciente){
    if(fila == NULL)
    exit(1);

    if (is_empty(fila) == 1)
    return 0;
    
    // transferindo da fila para a variavel paciente
    (*paciente) = (fila->pacientes)[fila->inicio];

    fila->inicio = (fila->inicio + 1) % TAMFILA;
    (fila->total)--; 
    return 1;
}

void excluir(FILA* fila){
    if(fila != NULL){
        if((fila->pacientes) != NULL){
            for (int i = 0; i < fila->tamanho; i++){
                if((fila->pacientes)[i].nome != NULL) 
                    free(((fila->pacientes))[i].nome);
            }
            
            free((fila->pacientes));
        }

        free(fila);
    }
}