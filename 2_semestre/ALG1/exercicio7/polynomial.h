typedef int DATA;

typedef struct node NODE;

typedef union{
    char atom;
    NODE* sublist;
}VAR;

struct node{
    int type;
    DATA value;
    VAR vars;
    struct node* next;
};

typedef struct list_polynomials{
    NODE *start, *end;
}LIST_P;

LIST_P* create_list();

/*  Allocates space for an atom (variable)
    PARAMETERS:
        x    : letter of the variable
        value: coefficient of the variable  */
NODE* atom(char x, DATA value);

/*  Allocates space from the sublist (set of variables)
    PARAMETERS:
        sublist: Node containing all variables
        value  : coefficient of the independent term
    */
NODE* sublist(NODE* sublist, DATA value);

/*  node_1.next = node_2    */
NODE* concat_vars(NODE* node_1, NODE* node_2);

/*  Add the sub-list in the list 
    PARAMETERS:
        list_p: list of the polynomials
        node  : node with the variables                 */
void add_in_the_list(LIST_P* list_p, NODE* node);

/*  Frees up all the space allocated to a list   */
void liberate(NODE* node);

/*  Displays a list from a node  */
void print(NODE* node);

/*  Reads a polynomial from input    */
int receive_polynomial(LIST_P* list_p);

/*  Calculates the result of the sum of all polynomials  */
LIST_P* calculate(LIST_P* list_p);

/*  Free the stored space for a list   */
void liberate_list(LIST_P* list_p);

/*  Remove '\r' and '\n'
    Also check if the EOF was found and return 1 */
int clear_buffer();