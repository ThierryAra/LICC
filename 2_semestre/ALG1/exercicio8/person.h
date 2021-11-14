#ifndef PERSON
#define PERSON
#include"memory_bank.h"

/*  Searches the ID in the memory bank and returns this position 
    or -2 if it doesn't find it
    PARAMETERS:
        mem_bank   : memory bank with all data
        ID         : required value
        penultimate: position before the found ID               */
int search_ID(MEM_BANK* mem_bank, int ID, int* penultimate);

/*  Adds the people (person_t x) in order of ID, return 1 */
int insert_sorted(MEM_BANK* mem_bank, person_t x);

/*  Removes a certain ID from bank
    Return -1 if the bank is empty
            0 if the value was not found
            1 if the removal has been done */
int remove_ID(MEM_BANK* mem_bank, int ID);

/*  Print all the people 
    Return 0 if the bank is empty
           1 print occurred       */
int print_people(MEM_BANK* mem_bank);
#endif