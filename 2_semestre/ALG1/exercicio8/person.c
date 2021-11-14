#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"person.h"

int get_node_ID(MEM_BANK* mem_bank, int ordem, int ID, int* penultimate){
    assert(mem_bank != NULL);

    if(mem_bank->p_empty == -1)
        return -1;
    else if(ordem == 0){ //value in the final
        int pos = mem_bank->p_empty;
        mem_bank->p_empty = mem_bank->v[pos].next;
        mem_bank->v[pos].next = -1;

        return pos;
    }else if(ordem == 1){ //orderly insert
        int i = mem_bank->start;
        int pos;
        *penultimate = mem_bank->start;

        while(i != -1){
            if(mem_bank->v[i].info.ID > ID){
                pos = i;
                return pos;
            }

            *penultimate = i;
            i = mem_bank->v[i].next;
        }

        pos = mem_bank->p_empty;
        return (pos);
    }
}

int insert_person(MEM_BANK* mem_bank, person_t x){
    assert(mem_bank != NULL);

    int pos = mem_bank->p_empty;
    mem_bank->p_empty = mem_bank->v[pos].next;
    mem_bank->v[pos].next = -1;
    
    mem_bank->v[pos].info = x;
    
    if(mem_bank->start == -1)
        mem_bank->start = pos;
    else
        mem_bank->v[mem_bank->end].next = pos;


    mem_bank->end = pos;
    return 1;
}

int insert_sorted(MEM_BANK* mem_bank, person_t x){
    assert(mem_bank != NULL);

    int penultimate;
    int pos = get_node_ID(mem_bank, 1, x.ID, &penultimate);
    
    if(pos == mem_bank->p_empty){
        insert_person(mem_bank, x);
        return 1;
    }
    
    int empty = mem_bank->p_empty;
    
    mem_bank->v[empty].info = x;
    
    mem_bank->p_empty = mem_bank->v[empty].next;
    
    if(pos == mem_bank->start){
        mem_bank->v[empty].next = mem_bank->start;
        mem_bank->start = empty;

    }else{
        mem_bank->v[penultimate].next = empty;
        mem_bank->v[empty].next = pos;
    }
    
    return 1;
}

int search_ID(MEM_BANK* mem_bank, int ID, int* penultimate){
    assert(mem_bank != NULL);

    if(is_empty(mem_bank))
        return -2;
    
    int  i = mem_bank->start;
    *penultimate = -1;
    
    while(i != -1 && mem_bank->v[i].info.ID <= ID){
        if(mem_bank->v[i].info.ID == ID)
            return i;
        
        
        *penultimate = i;
        i = mem_bank->v[i].next;
    }
    
    return -2;
}

int remove_ID(MEM_BANK* mem_bank, int ID){
    assert(mem_bank != NULL);

    if(is_empty(mem_bank))
        return -1;

    int penultimate;
    int pos = search_ID(mem_bank, ID, &penultimate);
    if(pos == -2) //value does not exist in the memory bank
        return 0;

    if(pos == mem_bank->start)
        mem_bank->start = mem_bank->v[mem_bank->start].next;
    else if(pos == mem_bank->end){
        mem_bank->end = penultimate;
        mem_bank->v[penultimate].next = -1;
    }      
    else    //if the value is in the middle of the bank
        mem_bank->v[penultimate].next = mem_bank->v[pos].next;

    mem_bank->v[pos].next = mem_bank->p_empty;
    mem_bank->p_empty = pos;
    return 1;
}

int print_people(MEM_BANK* mem_bank){
    assert(mem_bank != NULL);

    if(is_empty(mem_bank)){
        return 0;
    }

    int i = mem_bank->start;

    while (i != -1){
        printf("%d, ", mem_bank->v[i].info.ID);
        printf("%s;", mem_bank->v[i].info.name);
        if(mem_bank->v[i].next != -1)
            printf(" ");
        i = mem_bank->v[i].next;
    }
    
    printf("\n");
    return 1;
}