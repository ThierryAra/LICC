#include <stdio.h>
#include <stdlib.h>


int top_stack = -1;
double *stack = NULL;
char character = ' ';

void calculation ();

int main () {

    while (1)
    {
        character = getchar();

        if (character == EOF){
            break;
        } else if (character == '+' || character == '-' || character == '*' || character == '/'){
            calculation ();
            // When counting, the position containing the second number is deallocated
            top_stack--;
            if (top_stack > 0)
                stack = realloc (stack, (top_stack + 1) * sizeof (double));
            else {
                top_stack = 0;
                stack = realloc (stack, 1 * sizeof (double));
            }
        } else if (character != ' '){
            ungetc (character, stdin);
            top_stack++;
            stack = realloc (stack, (top_stack + 1) * sizeof(double));
            scanf ("%lf", &stack[top_stack]);
        }
    }

    printf ("Resultado: %.6lf\n", stack[top_stack]);
    free (stack);
    return 0;
}

void calculation (){

    switch (character)
    {
    case '+':
        stack[top_stack - 1] = stack[top_stack - 1] + stack[top_stack];
        break;
    case '-':
        stack[top_stack - 1] = stack[top_stack - 1] - stack[top_stack];
        break;
    case '*':
        stack[top_stack - 1] = stack[top_stack - 1] * stack[top_stack];
        break;
    case '/':
        stack[top_stack - 1] = stack[top_stack - 1] / stack[top_stack];
    }
}