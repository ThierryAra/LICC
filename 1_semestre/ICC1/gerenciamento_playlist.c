//USP - SÃO CARLOS
//THIERRY DE SOUZA ARAUJO - 12681094

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct music {
    char *music_name;
    char *artist;
    unsigned int time;
} Music;


typedef struct playlist {
    char *playlist_name;
    int amount_musics;
    Music *list_musics;
} Playlist;

char *receive_strings ();
void add_musics (Playlist *playlist);
void print_playlist (Playlist playlist, Music *current_music);
void write_playlist (Playlist *playlist);
void read_playlist (Playlist *playlist);
void deallocate_playlist (Playlist *playlist);
void binaryToNum(char *binFilename);
FILE *open_archive (FILE *archive, char archive_opening[3], Playlist *playlist, char *archive_name);

int main () {
    int option = 0, music_index = 0;
    Playlist playlist;
    char *playlist_file = NULL;

    //identificando a playlist
    playlist.amount_musics = 0;
    playlist.list_musics = NULL;
    playlist.playlist_name = receive_strings ();
    
    Music *music_playing = NULL;

    do {
        scanf ("%i", &option);
        getchar();
        
        switch (option) {
            case 1:
                add_musics(&playlist);
                if (playlist.amount_musics == 1)
                    music_playing = &playlist.list_musics[0];
                break;
            case 2:
                print_playlist (playlist, music_playing);
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

            case 5: //salvar playlist
                write_playlist (&playlist);
                break;

            case 6: //abrir playlist nova
                read_playlist (&playlist);
                if (playlist.list_musics != NULL)
                    music_playing = &playlist.list_musics[0];
        }

    } while (option != 7);

    deallocate_playlist(&playlist);
    if (playlist_file != NULL) free(playlist_file);
    return 0;
}

void add_musics (Playlist *playlist){
    int music_index = playlist->amount_musics; 

    if (playlist->amount_musics < 15) {
        playlist->list_musics = realloc (playlist->list_musics, (playlist->amount_musics + 1) * sizeof(Music));

        Music *music_add = &playlist->list_musics[music_index];
        music_add->music_name = receive_strings();
        music_add->artist = receive_strings();
        scanf ("%i", &music_add->time);
        getchar();
        playlist->amount_musics++;  
        printf ("Music %s de %s adicionada com sucesso.\n", music_add->music_name, music_add->artist);
                //Music sucessfully added.
    } else 
        printf ("Playlist cheia!\n"); // Playlist full!
}

void print_playlist (Playlist playlist, Music *current_music) {
    printf ("---- Playlist: %s ----\n", playlist.playlist_name);
    printf ("Total de musicas: %d\n\n", playlist.amount_musics); //Total musics:

    for (int i = 0; i < playlist.amount_musics; i++)
    {
        if (current_music->music_name == playlist.list_musics[i].music_name)
            printf ("=== NOW PLAYING ===\n");
        
        printf ("(%i). '%s'\n", i + 1, playlist.list_musics[i].music_name);
        printf ("Artista: %s\n", playlist.list_musics[i].artist); // Artist: 
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

void write_playlist (Playlist *playlist){
    FILE *playlist_file = NULL;
    char *archive_name = receive_strings();
    playlist_file = open_archive (playlist_file, "wb", playlist, archive_name);
    int string_size;
    
    //dados de cabecalho
    string_size = strlen (playlist->playlist_name);
    fwrite(&string_size, sizeof(int), 1, playlist_file);
    fwrite(playlist->playlist_name, sizeof(char), string_size, playlist_file);
    fwrite(&playlist->amount_musics, sizeof(int), 1, playlist_file);

    //lista de musicas
    for (int i = 0; i < playlist->amount_musics; i++) {
        string_size = strlen (playlist->list_musics[i].music_name);
        fwrite(&string_size, sizeof(int), 1, playlist_file);
        fwrite (playlist->list_musics[i].music_name, sizeof(char), string_size, playlist_file);
        string_size = strlen (playlist->list_musics[i].artist);
        fwrite(&string_size, sizeof(int), 1, playlist_file);
        fwrite (playlist->list_musics[i].artist, sizeof(char), string_size, playlist_file);
        fwrite (&playlist->list_musics[i].time, sizeof(unsigned int), 1, playlist_file);
    }

    printf ("Playlist %s salva com sucesso.\n", archive_name);
    fclose (playlist_file);
    binaryToNum (archive_name);
    free (archive_name);
}

void read_playlist (Playlist *playlist){
    FILE *playlist_file = NULL;
    char *archive_name = receive_strings();
    playlist_file = open_archive (playlist_file, "rb", playlist, archive_name);
    int string_size = 0;
    deallocate_playlist (playlist);

    // cabecalho
    fread (&string_size, sizeof(int), 1, playlist_file);
    playlist->playlist_name = malloc ((string_size + 1) * sizeof(char));
    fread(playlist->playlist_name, sizeof(char), string_size, playlist_file);
    playlist->playlist_name[string_size] = '\0';
    fread(&playlist->amount_musics, sizeof(int), 1, playlist_file);
    // lista de musicas
    playlist->list_musics = malloc (playlist->amount_musics * sizeof (Music));
    for (int i = 0; i < playlist->amount_musics; i++) {
        //nome
        fread (&string_size, sizeof(int), 1, playlist_file);
        playlist->list_musics[i].music_name = malloc ((string_size + 1) * sizeof(char));
        fread (playlist->list_musics[i].music_name, sizeof(char), string_size, playlist_file);
        playlist->list_musics[i].music_name[string_size] = '\0';
        //artist
        fread (&string_size, sizeof(int), 1, playlist_file);
        playlist->list_musics[i].artist = malloc ((string_size + 1) * sizeof(char));
        fread (playlist->list_musics[i].artist, sizeof(char), string_size, playlist_file);
        playlist->list_musics[i].artist[string_size] = '\0';
        //time
        fread (&playlist->list_musics[i].time, sizeof(unsigned int), 1, playlist_file);
    }
    printf ("Playlist %s carregada com sucesso.\n", archive_name);
    fclose (playlist_file);
    binaryToNum (archive_name);
    free (archive_name);
}

void deallocate_playlist (Playlist *playlist) {
    free (playlist->playlist_name);
    for (int i = 0; i < playlist->amount_musics; i++)
    {
        free (playlist->list_musics[i].music_name);
        free (playlist->list_musics[i].artist);
    }
    if (playlist->list_musics != NULL) free(playlist->list_musics);
}

void binaryToNum(char *binFilename) { //Convert binary file to a value
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}

FILE *open_archive (FILE *archive, char archive_opening[3], Playlist *playlist, char *archive_name){
    archive = fopen (archive_name, archive_opening);
    if (archive != NULL){
        return archive;
    } else {
        printf ("Arquivo %s nao existe.\n", archive_name); // Archive not exist.
        deallocate_playlist (playlist);
        free (archive_name);
        exit(1);
    }
}

/* 

CASE TEST:

INPUT:
Essa playlist sera removida
1
Makin' Waves
Vicarious Visions
175
6
Amora_e_Manjericao.dat
2
7

OUTPUT:
Musica Makin' Waves de Vicarious Visions adicionada com sucesso.
Playlist Amora_e_Manjericao.dat carregada com sucesso.
4740.890000
---- Playlist: Amora e Manjericao ----
Total de musicas: 3

=== NOW PLAYING ===
(1). 'On Ira'
Artista: Zaz
Duracao: 178 segundos

(2). 'Comfortably Numb'
Artista: Pink Floyd
Duracao: 382 segundos

(3). 'Magic - Original Mix'
Artista: Nhato
Duracao: 339 segundos

 */