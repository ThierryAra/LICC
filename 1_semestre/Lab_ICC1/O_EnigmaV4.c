#include<stdio.h>
#include<string.h>

int main () {

    int rotor1[26], rotor2[26], rotor3[26], i, transfer, rodar_rot1, rodar_rot2 = 0;
    char mensagem = 'a';

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

    mensagem = getchar();
    while (mensagem != EOF)
    {
        for (int j = 0; j < 26 && mensagem != EOF; j++)
        {
            for (int k = 0; rodar_rot2 < 26 && mensagem != EOF; k++){
                
                //se 'mensagem[i]' for uma letra (a-z, A-Z), ele irá tranformá-la
                if ((mensagem >= 'a' && mensagem <= 'z')){
                    printf("%c", (char)(rotor3[rotor2[rotor1[mensagem - 'a']]] + 'a') );
                    rodar_rot1 = 1;
                }
                else if (mensagem >= 'A' && mensagem <= 'Z'){
                    printf("%c", (char)(rotor3[(rotor2[(rotor1[mensagem - 'A'])])] + 'A') );
                    rodar_rot1 = 1;
                }
                else 
                    printf("%c", mensagem);

                //rodar rotor1
                if (rodar_rot1 == 1){
                    transfer = rotor1[0];
                    for (int l = 0; l < 25; l++)
                    {
                        rotor1[l] = rotor1[l+1];
                    }
                    rotor1[25] = transfer;
                    rodar_rot1 = 0;
                    rodar_rot2++;
                }

                mensagem = getchar();
            }

            //rodar rotor2
            transfer = rotor2[0];
            for (int l = 0; l < 25; l++)
            {
                rotor2[l] = rotor2[l+1];
            }
            rotor2[25] = transfer;
            rodar_rot2 = 0;
        }

        //rodar rotor3
        transfer = rotor3[0];
        for (int l = 0; l < 25; l++)
        {
            rotor3[l] = rotor3[l+1];
        }
        rotor3[25] = transfer;
        rodar_rot2 = 0;
    }
    
    return 0;
}