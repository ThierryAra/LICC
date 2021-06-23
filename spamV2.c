//Não consegui fazer o outro modelo de codigo funcionar, existiam muitas variaveis pra cobrir

#include<stdio.h>
#include<string.h>

int main () {
    //vetor de tamanho 9 pois e o tamanho maior das palavras proibidas
    char linha = '0', palavra[10];
    int j = 0, spam = 0, cont = 0;

    while (1)
    {
        linha = getchar();
        if (cont < 77){
            if ((linha >= 'a' && linha <= 'z') || (linha >= 'A' && linha <= 'Z')){
                if (j <= 8){
                    palavra[j] = linha;
                    j++;
                    cont++;
                } 
                //se a palavra tiver mais de 9 letras ela sera maior q qualquer palavra proibida, logo, diferente delas
                else {
                    cont++;
                    j = 0;
                    palavra[j] = '\0'; 
                }
            } else if (linha == EOF){
                printf ("Inbox");
                break;
            }
            else {
                cont++;
                palavra[j] = '\0';
                if ((strcmp (palavra, "gratuito") == 0) || (strcmp (palavra, "gratuitos") == 0))
                    spam++;
                if ((strcmp (palavra, "atencao") == 0) || (strcmp (palavra, "urgente") == 0) || (strcmp (palavra, "urgentes") == 0))
                    spam++;
                else if ((strcmp (palavra, "imediato") == 0) || (strcmp (palavra, "zoombie") == 0) || (strcmp (palavra, "zoombies") == 0))
                    spam++;
                else if ((strcmp (palavra, "dinheiro") == 0) || (strcmp (palavra, "renda") == 0) || (strcmp (palavra, "fundo") == 0))
                    spam++;
                else if ((strcmp (palavra, "oferta") == 0) || (strcmp (palavra, "ofertas") == 0) || (strcmp (palavra, "fundos") == 0))
                    spam++;
                else if ((strcmp (palavra, "limitado") == 0) || (strcmp (palavra, "limitados") == 0) || (strcmp (palavra, "SOS") == 0))
                    spam++;
                else if ((strcmp (palavra, "oferta") == 0) || (strcmp (palavra, "ofertas") == 0))
                    spam++;
                else if ((strcmp (palavra, "ajuda") == 0) || (strcmp (palavra, "ajudas") == 0))
                    spam++;

                if (linha == '\n')
                    cont = 0;
                if (spam >= 2)
                {
                    printf ("Spam");
                    break;
                }

                palavra[0] = '\0';
                j = 0;
            }
        } else {
            printf ("Spam");
            break;
        }
    }

    return 0;
}