#ifndef BANCO
#define BANCO
#define TAM 200

struct person{
    int ID;
    char name[50];
};

typedef struct node{
    struct person info;
    int next;
}NODE;

struct mem_bank{
    NODE v[TAM];
    int start, end, p_empty;
};

typedef struct mem_bank MEM_BANK;
typedef struct person person_t;

MEM_BANK* create_bank();

int is_empty(MEM_BANK* mem_bank);

int is_full(MEM_BANK* mem_bank);

/*  Inserts x into the first free position of the bank of memory   */
//int insert(MEM_BANK* mem_bank, person_t x);

/*  Inserts x into its ordered position within the bank  */
//int orderly_insertion(MEM_BANK* mem_bank, person_t x);

/*  Removes the last value from the memory bank and assigns x */
int remove_data(MEM_BANK* mem_bank, person_t* x);

/*  Frees up the memory space allocated to mem_bank   */
void liberate(MEM_BANK* mem_bank);


#endif