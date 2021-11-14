#include<stdio.h>
#include<stdlib.h>
#define QTD_ABERTURA 200

typedef struct pilha_t{
    char* itens;
    int topo;
}PILHA;


PILHA* criar_pilha(){
    PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));
    if(pilha == NULL)
        return NULL;

    pilha->itens = (char*)malloc((QTD_ABERTURA * 2) * sizeof(char));
    if(pilha == NULL){
        return NULL;
        printf("FALHA MALLOC");
    }

    pilha->topo = -1;
    return pilha;
}

void destruir(PILHA* pilha){
    if(pilha != NULL){
        free(pilha->itens);
        free(pilha);
    }

    pilha = NULL;
}   

int cheia(PILHA* pilha){
    if(pilha == NULL)
        return 1;

    if(pilha->topo >= (QTD_ABERTURA * 2))
        return 1;
    else
        return 0;
}

int vazia(PILHA* pilha){
    if(pilha == NULL)
        return 1;

    if(pilha->topo == -1)
        return 1;
    else
        return 0;
}

int push(PILHA* pilha, char dado){
    if(pilha == NULL)
        return 0;

    if (cheia(pilha) == 1)
        return 0;

    pilha->topo += 1;
    pilha->itens[pilha->topo] = dado;
    return 1;
}

int pop(PILHA* pilha){
    if(pilha == NULL)
        return 0;

    pilha->topo -= 1;
    
    return 1;
}

int top(PILHA* pilha, char* dado){
    if(pilha == NULL)
        return 0;

    if(vazia(pilha) == 1)
        return 0;

    (*dado) = pilha->itens[pilha->topo]; 
    return 1;
}

int analisar_texto(PILHA* pilha){
    int qtd_entrada = 0;
    int parar = 1;
    int abertura_aspas = 0;
    
    char fechar[QTD_ABERTURA], topo_pilha;

    char caractere = getchar();
    if(!push(pilha, caractere))
        return 0;

    if(caractere == '"')
        abertura_aspas++;

    caractere = getchar();
    while(caractere != '\n' && caractere != EOF){
        printf("%c", caractere);
        top(pilha, &topo_pilha);
        
        /* if((qtd_entrada > QTD_ABERTURA))
            parar = 0; */

        switch(caractere){
            case '{':
                if(!push(pilha, '{'))
                    //parar = 0;
                
                qtd_entrada++;
                break;

            case '(':
                if(!push(pilha, '('))
                    //parar = 0;
                
                qtd_entrada++;
                break;

            case '[':
                if(!push(pilha, '['))
                    //parar = 0;
                
                qtd_entrada++;
                break;

            case '"':
                abertura_aspas++;
                break;

            case ']':
                if(topo_pilha != '[' || !pop(pilha))
                    parar = 0;

                break;
            case ')':
                if(topo_pilha != '(' || !pop(pilha))
                    parar = 0;
                
                break;
            case '}':
                 if(topo_pilha != '{' || !pop(pilha))
                    parar = 0;
                
                break;
            default:
                break;
        }

        caractere = getchar();
        
        if(parar == 0) //Evita manter a verificacao caso ja encontre erro
            break;
    }
    
    //Limpa a entrada para receber o proximo trecho
    while (caractere != EOF && caractere != '\n') 
        caractere = getchar();
    
    if((abertura_aspas % 2) != 0)
        parar = 0;

    if(caractere == EOF)
        ungetc(caractere, stdin);

    return parar;
}

int main(){

    PILHA* pilha_t;


    char caractere = getchar();
    while(caractere != 'b'){
        printf("%c", caractere);
        ungetc(caractere, stdin);

        pilha_t = criar_pilha();
        
        if(analisar_texto(pilha_t))
            printf("BALANCEADO\n");
        else
            printf("NÃO BALANCEADO\n");
    
        destruir(pilha_t);

        caractere = getchar();
    }

    return 0;
}