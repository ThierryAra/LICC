#ifndef BG
#define BG
typedef struct node NODE;
typedef struct b_number B_NUMBER;

struct node{
    int info;
    NODE *prev, *next;
};

struct b_number{
    int signal;
    NODE *start, *end; 
};

B_NUMBER* create();

void liberate(B_NUMBER* l);

int insert(B_NUMBER* l, char node[]);

B_NUMBER* SUM(B_NUMBER* num1, B_NUMBER* num2);

int BIG(B_NUMBER* num1, B_NUMBER* num2);

int SML(B_NUMBER* num1, B_NUMBER* num2);

int EQL(B_NUMBER* num1, B_NUMBER* num2);

int print(B_NUMBER* l);

int inverted_print(B_NUMBER* l);

#endif