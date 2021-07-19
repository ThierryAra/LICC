#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct musica {
    char *nome_musica;
    char *artista;
    unsigned int tempo;
} Musica;


typedef struct playlist {
    char *nome_playlist;
    int qtd_musicas;
    Musica *lista_musicas;
} Playlist;

char *receber_strings ();

void adicionar_musicas (Musica *musica);

void printar_playlist (Playlist playlist, Musica *musica_atual);

int main () {
    int opcao = 0, indice_musica = 0;
    Playlist playlist;
    playlist.qtd_musicas = 0;
    playlist.lista_musicas = NULL;
    Musica *musica_tocando;

    //identificando a playlist
    playlist.nome_playlist = receber_strings ();
    
    do
    {
        scanf ("%i", &opcao);
        getchar();
        
        switch (opcao)
        {
            case 1:
                if (playlist.qtd_musicas < 15) {
                    playlist.lista_musicas = realloc (playlist.lista_musicas, (playlist.qtd_musicas + 1) * sizeof(Musica));
                    adicionar_musicas(&(playlist.lista_musicas[playlist.qtd_musicas]));
                    playlist.qtd_musicas++;  
                    if (playlist.qtd_musicas == 1){
                        musica_tocando = &playlist.lista_musicas[0];
                    }     
                } else 
                    printf ("Playlist cheia!\n");
                break;
            
            case 2:
                printar_playlist (playlist, musica_tocando);
                break;
            case 3:
                if (indice_musica < 15 && indice_musica <= playlist.qtd_musicas){
                    indice_musica++;
                    musica_tocando = &playlist.lista_musicas[indice_musica];
                }
                break;
            case 4:
                if (indice_musica >= 0){
                    indice_musica--;
                    musica_tocando = &playlist.lista_musicas[indice_musica];
                }
                break;
        }

    } while (opcao != 5);

    for (int i = 0; i < playlist.qtd_musicas; i++)
    {
        free(playlist.lista_musicas[i].artista);
        free(playlist.lista_musicas[i].nome_musica);
    }
    free(playlist.nome_playlist);
    free(playlist.lista_musicas);
    return 0;
}

void adicionar_musicas (Musica *musica){
    musica->nome_musica = receber_strings();
    musica->artista = receber_strings();
    scanf ("%i", &musica->tempo);
    getchar();

    printf ("Musica %s de %s adicionada com sucesso.\n", musica->nome_musica, musica->artista);
}

void printar_playlist (Playlist playlist, Musica *musica_atual) {
    printf ("---- Playlist: %s ----\n", playlist.nome_playlist);
    printf ("Total de musicas: %d\n\n", playlist.qtd_musicas);

    for (int i = 0; i < playlist.qtd_musicas; i++)
    {
        if (musica_atual->nome_musica == playlist.lista_musicas[i].nome_musica)
            printf ("=== NOW PLAYING ===\n");
        
        printf ("(%i). '%s'\n", i + 1, playlist.lista_musicas[i].nome_musica);
        printf ("Artista: %s\n", playlist.lista_musicas[i].artista);
        printf ("Duracao: %i segundos\n\n", playlist.lista_musicas[i].tempo);
    }   
}

char *receber_strings () {
    char entrada;
    char *string = NULL;
    int i = 1;

    while ((entrada = getchar()) != '\n') {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = entrada;
        i++;
    }
    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}