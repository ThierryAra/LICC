#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"memory_bank.h"

MEM_BANK* create_bank(){
    int i;

    MEM_BANK* mem_bank = malloc(sizeof(MEM_BANK));

    for (i = 0; i < TAM - 1; i++){
        mem_bank->v[i].next = i + 1;
    }
    
    mem_bank->v[i].next = -1;
    mem_bank->end = 0;
    mem_bank->start = -1;
    mem_bank->p_empty = 0;
}

int is_empty(MEM_BANK* mem_bank){
    assert(mem_bank != NULL);

    return (mem_bank->start == -1);
}

int is_full(MEM_BANK* mem_bank){
    assert(mem_bank != NULL);

    return (mem_bank->p_empty == -1);
}

void liberate_node(MEM_BANK* mem_bank, int pos){
    assert(mem_bank != NULL);
    assert(pos >= 0 && pos < TAM);

    mem_bank->v[pos].next = mem_bank->p_empty;
    mem_bank->p_empty = pos;
}

int get_node(MEM_BANK* mem_bank, int ordem, person_t x){
    assert(mem_bank != NULL);

    if(mem_bank->p_empty == -1)
        return -1;
    else if(ordem == 0){ //value in the final
        int pos = mem_bank->p_empty;
        mem_bank->p_empty = mem_bank->v[pos].next;
        mem_bank->v[pos].next = -1;

        return pos;
    }else if(ordem == 1){ //orderly insertion
        int i = mem_bank->start, pos;
        while(i != -1){

            if(mem_bank->v[i].info.ID > x.ID){
                pos = i;
                return pos;
            }

            i = mem_bank->v[i].next;
        }

        pos = mem_bank->p_empty;
        return (pos);
    }
}

int insert(MEM_BANK* mem_bank, person_t x){
    int pos = get_node(mem_bank, 0, x);
    
    if(pos == -1)
        return 0;

    mem_bank->v[pos].info = x;
    
    if(mem_bank->end != -1)
        mem_bank->v[mem_bank->end].next = pos;
    
    mem_bank->end = pos;

    if(mem_bank->start == -1)
        mem_bank->start = pos;

    return 1;
}

int orderly_insert(MEM_BANK* mem_bank, person_t x){
    int pos = get_node(mem_bank, 1, x);
    
    if(pos == -1)
        return 0;

    if(pos == mem_bank->p_empty){
        insert(mem_bank, x);
        return 1;
    }

    int i = mem_bank->v[pos].next;
    person_t previous_info  = mem_bank->v[pos].info;
    person_t next_info      = mem_bank->v[pos].info;

    //moves all (but the last) values to a position ahead
    while (i != -1){
        next_info = mem_bank->v[i].info;
        mem_bank->v[i].info = previous_info;  

        i = mem_bank->v[i].next;  
        previous_info = next_info;
    }

    mem_bank->v[pos].info = x;
    
    //add new position
    mem_bank->v[mem_bank->end].next = mem_bank->p_empty; 

    //p_empty becomes the next position in the empty list
    int empty = mem_bank->p_empty; 
    mem_bank->p_empty = mem_bank->v[empty].next;
    
    //set the new position for the end of list
    mem_bank->v[empty].info = next_info;
    mem_bank->v[empty].next = i;
    mem_bank->end = empty;
    
    return 1;
}

int remove_data(MEM_BANK* mem_bank, person_t* x){
    assert(mem_bank != NULL);

    if(mem_bank->start == -1)
        return 0;

    *x = mem_bank->v[mem_bank->start].info;

    int pos = mem_bank->start;
    mem_bank->start = mem_bank->v[pos].next;
    liberate_node(mem_bank, pos);

    return 1;
}

void liberate(MEM_BANK* mem_bank){
    assert(mem_bank != NULL);

    free(mem_bank);

    mem_bank = NULL;
}
