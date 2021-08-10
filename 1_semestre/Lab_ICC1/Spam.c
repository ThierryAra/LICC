#include<stdio.h>
#include<string.h>

int main () {
    // size vector 10 because it is the largest size of the forbidden words
    char line = '0', word[10];
    int j = 0, spam = 0, count = 0;

    while (1)
    {
        line = getchar();
        if (count < 77){
            if ((line >= 'a' && line <= 'z') || (line >= 'A' && line <= 'Z')){
                if (j <= 8){
                    word[j] = line;
                    j++;
                    count++;
                } 
                // If the word is longer than 9 letters it will be larger than any forbidden word, therefore, different from them
                else {
                    count++;
                    j = 0;
                    word[j] = '\0'; 
                }
            } else if (line == EOF){
                printf ("Inbox");
                break;
            }
            else {
                count++;
                word[j] = '\0';
                if ((strcmp (word, "gratuito") == 0) || (strcmp (word, "gratuitos") == 0))
                    spam++;
                if ((strcmp (word, "atencao") == 0) || (strcmp (word, "urgente") == 0) || (strcmp (word, "urgentes") == 0))
                    spam++;
                else if ((strcmp (word, "imediato") == 0) || (strcmp (word, "zoombie") == 0) || (strcmp (word, "zoombies") == 0))
                    spam++;
                else if ((strcmp (word, "dinheiro") == 0) || (strcmp (word, "renda") == 0) || (strcmp (word, "fundo") == 0))
                    spam++;
                else if ((strcmp (word, "oferta") == 0) || (strcmp (word, "ofertas") == 0) || (strcmp (word, "fundos") == 0))
                    spam++;
                else if ((strcmp (word, "limitado") == 0) || (strcmp (word, "limitados") == 0) || (strcmp (word, "SOS") == 0))
                    spam++;
                else if ((strcmp (word, "oferta") == 0) || (strcmp (word, "ofertas") == 0))
                    spam++;
                else if ((strcmp (word, "ajuda") == 0) || (strcmp (word, "ajudas") == 0))
                    spam++;

                if (line == '\n')
                    count = 0;
                if (spam >= 2)
                {
                    printf ("Spam");
                    break;
                }

                word[0] = '\0';
                j = 0;
            }
        } else {
            printf ("Spam");
            break;
        }
    }

    return 0;
}