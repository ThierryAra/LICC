#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct music {
    char *artist_name;
    char *artist;
    unsigned int time;
} Music;


typedef struct playlist {
    char *playlist_name;
    int amount_musics;
    Music *list_musics;
} Playlist;

char *receive_strings ();

void add_music (Music *music);

void printar_playlist (Playlist playlist, Music *current_music);

int main () {
    int option = 0, music_index = 0;
    Playlist playlist;
    playlist.amount_musics = 0;
    playlist.list_musics = NULL;
    Music *music_playing;

    //identificando a playlist
    playlist.playlist_name = receive_strings ();
    
    do
    {
        scanf ("%i", &option);
        getchar();
        
        switch (option)
        {
            case 1:
                if (playlist.amount_musics < 15) {
                    playlist.list_musics = realloc (playlist.list_musics, (playlist.amount_musics + 1) * sizeof(Music));
                    add_music(&(playlist.list_musics[playlist.amount_musics]));
                    playlist.amount_musics++;  
                    if (playlist.amount_musics == 1){
                        music_playing = &playlist.list_musics[0];
                    }     
                } else 
                    printf ("Playlist cheia!\n");
                break;
            
            case 2:
                printar_playlist (playlist, music_playing);
                break;
            case 3:
                if (music_index < 15 && music_index <= playlist.amount_musics){
                    music_index++;
                    music_playing = &playlist.list_musics[music_index];
                }
                break;
            case 4:
                if (music_index >= 0){
                    music_index--;
                    music_playing = &playlist.list_musics[music_index];
                }
                break;
        }

    } while (option != 5);

    for (int i = 0; i < playlist.amount_musics; i++)
    {
        free(playlist.list_musics[i].artist);
        free(playlist.list_musics[i].artist_name);
    }
    free(playlist.playlist_name);
    free(playlist.list_musics);
    return 0;
}

void add_music (Music *music){
    music->artist_name = receive_strings();
    music->artist = receive_strings();
    scanf ("%i", &music->time);
    getchar();

    printf ("Musica %s de %s adicionada com sucesso.\n", music->artist_name, music->artist);
}           // Music successfully added.

void printar_playlist (Playlist playlist, Music *current_music) {
    printf ("---- Playlist: %s ----\n", playlist.playlist_name);
    printf ("Total de musicas: %d\n\n", playlist.amount_musics); // Total songs:

    for (int i = 0; i < playlist.amount_musics; i++)
    {
        if (current_music->artist_name == playlist.list_musics[i].artist_name)
            printf ("=== NOW PLAYING ===\n");
        
        printf ("(%i). '%s'\n", i + 1, playlist.list_musics[i].artist_name);
        printf ("Artista: %s\n", playlist.list_musics[i].artist); //Artist: 
        printf ("Duracao: %i segundos\n\n", playlist.list_musics[i].time); // Duration:
    }   
}

char *receive_strings () {
    char input;
    char *string = NULL;
    int i = 1;

    while ((input = getchar()) != '\n') {
        string = (char*)realloc(string, i * sizeof(char));
        *(string + (i - 1)) = input;
        i++;
    }
    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char));
    *(string + (i - 1)) = '\0';
    return string;
}