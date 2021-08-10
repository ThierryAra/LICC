// Word_Counter
#include<stdio.h>
#include<string.h>

int main () {

    int lines = 0, words = 0, character = 0, repetition = 1;
    char text;

    text = getchar();
    while (text != EOF)
    {
        character++;

        // Deals with repetitions of '\n' or ' '
        if (text == ' ' || text == '\n' || text == '\t' || text == '\r')
            repetition = 1;
        // If there is a ' ' or '\n' and then another character, it means that there was a word before
        else if (repetition == 1){
            repetition = 0;
            words++;
        }

        if (text == '\n')
            lines++;


        text = getchar();
    } 

    printf("lines\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", lines, words, character);

  return 0;
}
