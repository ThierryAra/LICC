#include<stdio.h>
#include<stdlib.h>

int main () {

    char mem;

    FILE *arquivo = fopen ("Codigo-run.c", "w");

    fprintf (arquivo, "%s", "#include <stdio.h>\n\nint main() {\nchar mem[30000];\nint i = 0;\n\n"
                            "for (int j = 0; j < 30000; j++) {\nmem[j] = 0; \n}\n");

    do {
        mem = getchar();
        switch (mem)
        {
        case '+': 
            fprintf (arquivo, "%s", "mem[i]++;\n");
            break;
        case '-': 
            fprintf (arquivo, "%s", "mem[i]--;\n");
            break;
        case '<': 
            fprintf (arquivo, "%s", "i--;\n");
            break;
        case '>': 
            fprintf (arquivo, "%s", "i++;\n");
            break;
        case '.': 
            fprintf (arquivo, "%s", "putchar(mem[i]);\n");
            break;
        case '[': 
            fprintf (arquivo, "%s", "while (mem[i]) {\n");
            break;
        case ']': 
            fprintf (arquivo, "%s", "}\n");
            break;
        
        default:
            break;
        }

    } while (mem != EOF);
    
    fprintf (arquivo, "%s",  "\nprintf(\"\\n\");\n\nfor (int j = 0; j < 30000; j++) {\n\tif (mem[j] != 0) {\n"
                             "\tprintf(\"%d \", mem[j]); \n} \n} \nprintf(\"\\n\"); \n\nreturn 0; \n}");

    fclose (arquivo);

    system("gcc Codigo-run.c -o codigoC-run");
    system("./codigoC-run");
    return 0;
}