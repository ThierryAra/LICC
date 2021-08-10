#include<stdio.h>
#include<string.h>

int main () {

    int rotor1[26], rotor2[26], rotor3[26];
    int i, aux;
    int rotate_rotor1 = 0, rotate_rotor2 = 0;
    char message = 'a';

    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");

    // 0 = 'a', 1 = 'b'...
    for (i = 0; i < 26; i++)
    {
        scanf ("%i", &rotor1[i]);
    }
    for (i = 0; i < 26; i++)
    {
        scanf ("%i", &rotor2[i]);
    }
    for (i = 0; i < 26; i++)
    {
        scanf ("%i", &rotor3[i]);
    }

    scanf("%*[\r\n]s");
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");

    message = getchar();
    while (message != EOF)
    {
        for (int j = 0; j < 26 && message != EOF; j++)
        {
            for (int k = 0; rotate_rotor2 < 26 && message != EOF; k++){
                
                // If 'message[i]' is a letter (a-z, A-Z), it will tranform it
                if ((message >= 'a' && message <= 'z')){
                    printf("%c", (char)(rotor3[rotor2[rotor1[message - 'a']]] + 'a') );
                    rotate_rotor1 = 1;
                }
                else if (message >= 'A' && message <= 'Z'){
                    printf("%c", (char)(rotor3[(rotor2[(rotor1[message - 'A'])])] + 'A') );
                    rotate_rotor1 = 1;
                }
                else 
                    printf("%c", message);

                // Rotate rotor1
                if (rotate_rotor1 == 1){
                    aux = rotor1[0];
                    for (int l = 0; l < 25; l++)
                    {
                        rotor1[l] = rotor1[l+1];
                    }
                    rotor1[25] = aux;
                    rotate_rotor1 = 0;
                    rotate_rotor2++;
                }

                message = getchar();
            }

            // Rotate rotor2
            aux = rotor2[0];
            for (int l = 0; l < 25; l++)
            {
                rotor2[l] = rotor2[l+1];
            }
            rotor2[25] = aux;
            rotate_rotor2 = 0;
        }

        // Rotate rotor3
        aux = rotor3[0];
        for (int l = 0; l < 25; l++)
        {
            rotor3[l] = rotor3[l+1];
        }
        rotor3[25] = aux;
        rotate_rotor2 = 0;
    }
    
    return 0;
}