#include<stdio.h>
#include<stdlib.h>
int main () {

    char mem;
    int conchetes_aberto = 0;

    FILE *traduzido = fopen ("codigoC.c", "w");
    fprintf (traduzido, "%s", "#include<stdio.h>\n#include<stdlib.h>\n#define TAMANHO_MEM 30000 \n"
            "int main() {\nint mem[TAMANHO_MEM], i = 0, loop = 0;\n");

    // Seta todos os lugares da memória para 0.
    fprintf (traduzido, "%s", "for (int j = 0; j < TAMANHO_MEM; j++) {\n\tmem[j] = 0; \n}\n\n");

    /* Começo do código traduzido de BF */
    mem = getchar();
    while (mem != EOF) {
        switch (mem) {
            case '+':
                fprintf (traduzido, "%s", "mem[i]++;\n");
                break;
            case '-':
                fprintf (traduzido, "%s", "mem[i]--;\n");
                break;
            case '>':
                fprintf (traduzido, "%s", "i++;\n");
                break;
            case '<':
                fprintf (traduzido, "%s", "i--;\n");
                break;
            case '.':
                fprintf (traduzido, "%s", "putchar(mem[i]);\n");
                break;
            case '[':
                //garante que so entre no loop caso a posicao tenha um valor > 0
                fprintf (traduzido, "%s", "if (mem[i] > 0) \n\tloop = 1;\n");
                fprintf (traduzido, "%s", "if (loop == 1){\n\tloop = 0;\n\twhile (mem[i]) {\n");
                conchetes_aberto += 1;
                break;
            case ']':
                //garante que não adicione a } } sem que tenha sido aberta previamente
                if (conchetes_aberto > 0){
                    fprintf (traduzido, "%s", "\t}\n}\n");
                    conchetes_aberto -= 1;
                }
        }
        mem = getchar();        
    }

    fprintf (traduzido, "%s", "\nputchar(10);\nfor (int j = 0; j < TAMANHO_MEM; j++) {\n\tif (mem[j] != 0) "
            "{\n\t\tprintf (");
    fprintf (traduzido, "%c%s%c", 34, "%d ", 34); //' "%d" '
    fprintf (traduzido, "%s",", mem[j]);\n\t}\n}\nreturn 0;\n}");
    fclose (traduzido);

    system("gcc codigoC.c -o codigoC-run");
    system("./codigoC-run");
    return 0;
}