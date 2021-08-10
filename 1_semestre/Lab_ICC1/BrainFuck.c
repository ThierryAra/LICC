// BrainF*ck
#include<stdio.h>
#include<stdlib.h>

int main () {

    char mem;

    FILE *flie = fopen ("Codigo-run.c", "w");

    fprintf (flie, "%s", "#include <stdio.h>\n\nint main() {\nchar mem[30000];\nint i = 0;\n\n"
                            "for (int j = 0; j < 30000; j++) {\nmem[j] = 0; \n}\n");

    do {
        mem = getchar();
        switch (mem)
        {
        case '+': 
            fprintf (flie, "%s", "mem[i]++;\n");
            break;
        case '-': 
            fprintf (flie, "%s", "mem[i]--;\n");
            break;
        case '<': 
            fprintf (flie, "%s", "i--;\n");
            break;
        case '>': 
            fprintf (flie, "%s", "i++;\n");
            break;
        case '.': 
            fprintf (flie, "%s", "putchar(mem[i]);\n");
            break;
        case '[': 
            fprintf (flie, "%s", "while (mem[i]) {\n");
            break;
        case ']': 
            fprintf (flie, "%s", "}\n");
            break;
        
        default:
            break;
        }

    } while (mem != EOF);
    
    fprintf (flie, "%s",  "\nprintf(\"\\n\");\n\nfor (int j = 0; j < 30000; j++) {\n\tif (mem[j] != 0) {\n"
                             "\tprintf(\"%d \", mem[j]); \n} \n} \nprintf(\"\\n\"); \n\nreturn 0; \n}");

    fclose (flie);

    system("gcc Codigo-run.c -o codigoC-run");
    system("./codigoC-run");
    return 0;
}