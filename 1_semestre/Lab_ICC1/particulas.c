#include<stdio.h>
#define LARG 65
#define ALT 32
//troca duas posicoes da matriz
#define troca(matriz, yo, xo, y, x) ({char c = matriz[y][x]; matriz[y][x] = matriz[yo][xo];  matriz[yo][xo] = c;})
//caso o campo seja agua(~) ou ar(' '), retorna 1 e permite a troca
#define caso_areia(matriz, y, x) ((matriz[y][x] == '~') || (matriz[y][x] == ' '))
//caso o campo seja ar(' '), retorna 1 e permite a troca
#define caso_agua(matriz, y, x) ((matriz[y][x] == ' '))

void copiar_matriz (char matriz[ALT][LARG], char matriz_copiada[ALT][LARG]);

void mudar_fisica (char matriz[ALT][LARG], char copia_matriz[ALT][LARG]);

void print_matriz (char matriz[ALT][LARG]);

void inicializar_simulador (char matriz[ALT][LARG]);

int main () {

    int n_frames, frame, x, y;
    char nova_particula, simulador[ALT][LARG], copia_simulador[ALT][LARG];
    inicializar_simulador(simulador);

    scanf("%d", &n_frames);

    int contador = 0;
    system ("clear && echo \"\033[1,1H\"");
    while (contador < n_frames) {

        int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);
        if (n_lido == EOF) 
            frame = n_frames;

        //modifica todos os frames até chegar ao que foi dado no scanf
        while (contador < frame) {
            printf("frame: %d\n", contador + 1);
            print_matriz(simulador);
            mudar_fisica(simulador, copia_simulador);
            system ("echo \"\033[1;1H\" && sleep .150"); 
            copiar_matriz(simulador, copia_simulador);
            contador++;
        }

        // Se há uma particula a ser criada, crie ela
        if (n_lido != EOF) {
            simulador[y][x] = nova_particula;
        }
    }

    return 0;
}

void copiar_matriz (char matriz[ALT][LARG], char matriz_copiada[ALT][LARG]){
    for (int y = 0; y < ALT; y++)
    {
        for (int x = 0; x < LARG; x++)
        {
            matriz[y][x] = matriz_copiada[y][x];
        }
    }
}

void mudar_fisica (char matriz[ALT][LARG], char copia_matriz[ALT][LARG]) {

    copiar_matriz(copia_matriz, matriz);

    for (int y = 0; y < ALT; y++)
    {
        for (int x = 0; x < LARG; x++)
        {
            switch (matriz[y][x])
            {
                //caso seja areia (direcao)
                case '#':
                    if ((y + 1) < ALT){
                        // v
                        if (caso_areia(matriz, y + 1, x)){
                                troca (copia_matriz, y, x, y + 1, x);
                        
                        // v + <
                        } else if (caso_areia(matriz, y + 1, x - 1)){
                            if ((x - 1) >= 0)
                                troca (copia_matriz, y, x, y + 1, x - 1);
                        
                        // v + >
                        } else if (caso_areia(matriz, y + 1, x + 1)){
                            if ((x + 1) < 64)
                                troca (copia_matriz, y, x, y + 1, x + 1);
                        }
                    }
                    break;
                //caso seja agua: (direcao)
                case '~':
                    // v
                    if (caso_agua(matriz, y + 1, x) && ((y + 1) < ALT))
                        troca (copia_matriz, y, x, y + 1, x);
                    
                    // v + <
                    else if (caso_agua(matriz, y + 1, x - 1) && ((y + 1) < ALT)){
                        if ((x - 1) >= 0)
                            troca (copia_matriz, y, x, y + 1, x - 1);
                    
                    // v + >
                    } else if (caso_agua(matriz, y + 1, x + 1) && ((y + 1) < ALT)){
                        if ((x + 1) < 64)
                            troca (copia_matriz, y, x, y + 1, x + 1);
                    }
                    // <
                    else if (caso_agua(matriz, y, x - 1)){
                            if ((x - 1) >= 0)
                                troca (copia_matriz, y, x, y, x - 1);
                    
                    // >
                    } else if (caso_agua(matriz, y, x + 1)){
                            if ((x + 1) < 64)
                                troca (copia_matriz, y, x, y, x + 1);
                    }
                    break;
                //caso seja ar ou pedra, nada deve ser feito
                case ' ':
                    break;
                case '@':
                    break;
            }
                    
        }
    }
}

void print_matriz (char matriz[ALT][LARG]){

    for (int y = 0; y < ALT; y++)
    {
        for (int x = 0; x < LARG; x++)
        {
            printf ("%c", matriz[y][x]);
        }
    }

}

void inicializar_simulador (char matriz[ALT][LARG]){
    int y, x;

   for (y = 0; y < ALT; y++)
    {
        for (x = 0; x < (LARG - 1); x++)
        {
            matriz[y][x] = ' ';
        }
        matriz[y][x] = '\n';
    } 

}