//USP - SÃO CARLOS
//THIERRY DE SOUZA ARAUJO - 12681094

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
void adicionar_musicas (Playlist *playlist);
void printar_playlist (Playlist playlist, Musica *musica_atual);
void escrever_playlist (Playlist *playlist);
void ler_playlist (Playlist *playlist);
void desalocar_playlist (Playlist *playlist);
void binaryToNum(char *binFilename);
FILE *abrir_arquivo (FILE *arquivo, char abertura[3], Playlist *playlist, char *nome_arquivo);

int main () {
    int opcao = 0, indice_musica = 0;
    Playlist playlist;
    char *arquivo_playlist = NULL;

    //identificando a playlist
    playlist.qtd_musicas = 0;
    playlist.lista_musicas = NULL;
    playlist.nome_playlist = receber_strings ();
    
    Musica *musica_tocando = NULL;

    do {
        scanf ("%i", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                adicionar_musicas(&playlist);
                if (playlist.qtd_musicas == 1)
                    musica_tocando = &playlist.lista_musicas[0];
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

            case 5: //salvar playlist
                escrever_playlist (&playlist);
                break;

            case 6: //abrir playlist nova
                ler_playlist (&playlist);
                if (playlist.lista_musicas != NULL)
                    musica_tocando = &playlist.lista_musicas[0];
        }

    } while (opcao != 7);

    desalocar_playlist(&playlist);
    if (arquivo_playlist != NULL) free(arquivo_playlist);
    return 0;
}

void adicionar_musicas (Playlist *playlist){
    int indice_musica = playlist->qtd_musicas; 

    if (playlist->qtd_musicas < 15) {
        playlist->lista_musicas = realloc (playlist->lista_musicas, (playlist->qtd_musicas + 1) * sizeof(Musica));

        Musica *musica_add = &playlist->lista_musicas[indice_musica];
        musica_add->nome_musica = receber_strings();
        musica_add->artista = receber_strings();
        scanf ("%i", &musica_add->tempo);
        getchar();
        playlist->qtd_musicas++;  
        printf ("Musica %s de %s adicionada com sucesso.\n", musica_add->nome_musica, musica_add->artista);
    } else 
        printf ("playlist->cheia!\n");
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

void escrever_playlist (Playlist *playlist){
    FILE *arquivo_playlist = NULL;
    char *nome_arquivo = receber_strings();
    arquivo_playlist = abrir_arquivo (arquivo_playlist, "wb", playlist, nome_arquivo);
    int tamanho_string;
    
    //dados de cabecalho
    tamanho_string = strlen (playlist->nome_playlist);
    fwrite(&tamanho_string, sizeof(int), 1, arquivo_playlist);
    fwrite(playlist->nome_playlist, sizeof(char), tamanho_string, arquivo_playlist);
    fwrite(&playlist->qtd_musicas, sizeof(int), 1, arquivo_playlist);

    //lista de musicas
    for (int i = 0; i < playlist->qtd_musicas; i++) {
        tamanho_string = strlen (playlist->lista_musicas[i].nome_musica);
        fwrite(&tamanho_string, sizeof(int), 1, arquivo_playlist);
        fwrite (playlist->lista_musicas[i].nome_musica, sizeof(char), tamanho_string, arquivo_playlist);
        tamanho_string = strlen (playlist->lista_musicas[i].artista);
        fwrite(&tamanho_string, sizeof(int), 1, arquivo_playlist);
        fwrite (playlist->lista_musicas[i].artista, sizeof(char), tamanho_string, arquivo_playlist);
        fwrite (&playlist->lista_musicas[i].tempo, sizeof(unsigned int), 1, arquivo_playlist);
    }

    printf ("Playlist %s salva com sucesso.\n", nome_arquivo);
    fclose (arquivo_playlist);
    binaryToNum (nome_arquivo);
    free (nome_arquivo);
}

void ler_playlist (Playlist *playlist){
    FILE *arquivo_playlist = NULL;
    char *nome_arquivo = receber_strings();
    arquivo_playlist = abrir_arquivo (arquivo_playlist, "rb", playlist, nome_arquivo);
    int tamanho_string = 0;
    desalocar_playlist (playlist);

    // cabecalho
    fread (&tamanho_string, sizeof(int), 1, arquivo_playlist);
    playlist->nome_playlist = malloc ((tamanho_string + 1) * sizeof(char));
    fread(playlist->nome_playlist, sizeof(char), tamanho_string, arquivo_playlist);
    playlist->nome_playlist[tamanho_string] = '\0';
    fread(&playlist->qtd_musicas, sizeof(int), 1, arquivo_playlist);
    // lista de musicas
    playlist->lista_musicas = malloc (playlist->qtd_musicas * sizeof (Musica));
    for (int i = 0; i < playlist->qtd_musicas; i++) {
        //nome
        fread (&tamanho_string, sizeof(int), 1, arquivo_playlist);
        playlist->lista_musicas[i].nome_musica = malloc ((tamanho_string + 1) * sizeof(char));
        fread (playlist->lista_musicas[i].nome_musica, sizeof(char), tamanho_string, arquivo_playlist);
        playlist->lista_musicas[i].nome_musica[tamanho_string] = '\0';
        //artista
        fread (&tamanho_string, sizeof(int), 1, arquivo_playlist);
        playlist->lista_musicas[i].artista = malloc ((tamanho_string + 1) * sizeof(char));
        fread (playlist->lista_musicas[i].artista, sizeof(char), tamanho_string, arquivo_playlist);
        playlist->lista_musicas[i].artista[tamanho_string] = '\0';
        //tempo
        fread (&playlist->lista_musicas[i].tempo, sizeof(unsigned int), 1, arquivo_playlist);
    }
    printf ("Playlist %s carregada com sucesso.\n", nome_arquivo);
    fclose (arquivo_playlist);
    binaryToNum (nome_arquivo);
    free (nome_arquivo);
}

void desalocar_playlist (Playlist *playlist) {
    free (playlist->nome_playlist);
    for (int i = 0; i < playlist->qtd_musicas; i++)
    {
        free (playlist->lista_musicas[i].nome_musica);
        free (playlist->lista_musicas[i].artista);
    }
    if (playlist->lista_musicas != NULL) free(playlist->lista_musicas);
}

void binaryToNum(char *binFilename) {
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

FILE *abrir_arquivo (FILE *arquivo, char abertura[3], Playlist *playlist, char *nome_arquivo){
    arquivo = fopen (nome_arquivo, abertura);
    if (arquivo != NULL){
        return arquivo;
    } else {
        printf ("Arquivo %s nao existe.\n", nome_arquivo);
        desalocar_playlist (playlist);
        free (nome_arquivo);
        exit(1);
    }
}