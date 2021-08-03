#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void frame_art(char *name_of_archive, int  height, int width);
void receive_art(char *name_of_archive, int  *height, int *width, char ***art);
void save_art(char *name_of_archive, int  height, int width, char **art);
void paint_art(char color, int coordinate_y, int coordinate_x, int height, 
			     int width, char **art, char original_pixel);
void show_art(char **art,  int  height, int width);
char *receive_name ();

int main (){

	char *name_of_archive = NULL, filling, **art = NULL;
	int amount_filling = 0;
	int height_board = 0, width_board = 0;
	
	//dados de input
	name_of_archive = receive_name();
	scanf("%d", &amount_filling);
	getchar();

	//recebendo a art
	receive_art(name_of_archive, &height_board, &width_board, &art);

	printf("Arte inicial: \n"); // Initial art: 
	show_art(art, height_board, width_board);
	
	int coordinate_x = 0, coordinate_y = 0;
	 for (int i = 0; i < amount_filling; i++) {
		scanf("%c %d %d", &filling, &coordinate_y, &coordinate_x);
		getchar();
		//pixel que sera comparado na substituicao
		char original_pixel = art[coordinate_y][coordinate_x]; 

		paint_art(filling, coordinate_y, coordinate_x, height_board, 
				    width_board, art, original_pixel);

		printf("Arte apos a etapa %i: \n", i); // Art after step %i: 
		show_art(art, height_board, width_board);
	}
 
	//devolve a art ao arquivo (return the art to the archive)
	save_art(name_of_archive, height_board, width_board, art);  
	 
	printf("Arte enquadrada: \n"); // Framed art:  
	frame_art(name_of_archive, height_board, width_board); 

	free(name_of_archive);
	for (int i = 0; i < height_board; i++) free (art[i]);
	free(art);

	return 0;
}

void receive_art (char *name_of_archive, int  *height, int *width, char ***art){
	
	FILE *archive = fopen(name_of_archive, "r");
	if (archive == NULL) exit (EXIT_FAILURE);

	int  line = 0, column;
	char current_char;

	do {
		(*art) = realloc ((*art), (line + 1) * sizeof(char**));
		(*art)[line] = NULL;
		
		column = 0;
		do {
			current_char = fgetc(archive);
			if (current_char != EOF && current_char != '\n') {
				(*art)[line] = realloc((*art)[line], (column + 1) * sizeof(char*));
				
				(*art)[line][column] = current_char;
				column++;
			}
		} while (current_char != '\n' && !feof(archive));
		
		if (column > *width) *width = column;
		line++;
	} while(!feof (archive));

	*height = line;

	fclose (archive);
}

void paint_art (
	char color,
	int y, int x, 
	int height, int width,
	char **art, char original_pixel  )
{
	if (art[y][x] == original_pixel) {
		art[y][x] = color;
	}
	if (x + 1 < width) {
		if (art[y][x + 1] == original_pixel){
			art[y][x] = color;
			paint_art(color, y, x + 1, height, width, art, original_pixel);
		}
	}
	if (x - 1 >= 0) {
		if (art[y][x - 1] == original_pixel){
		art[y][x - 1] = color;
		paint_art(color, y, x - 1, height, width, art, original_pixel);
		}
	}
	if (y + 1 < height) {
		if (art[y + 1][x] == original_pixel){
			art[y + 1][x] = color;
			paint_art(color, y + 1, x, height, width, art, original_pixel);
		}
	}
	if (y - 1 >= 0) {
		if (art[y - 1][x] == original_pixel){
			art[y - 1][x] = color;
			paint_art(color, y - 1, x, height, width, art, original_pixel);
		}
	}
}

void save_art (
	char *name_of_archive, 
	int  height, int width,
	char **art )
{
	FILE *f_arte_ptr = fopen(name_of_archive, "w");
	if (f_arte_ptr == NULL) exit(EXIT_FAILURE);
	
	int y, x;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			if (y == height - 1 && x == width) break;
			fprintf(f_arte_ptr, "%c", art[y][x]);
		}
		//adiciona /n em todas a linhas, menos na ultima, que tera o EOF
		//add /n to all the lines, except the last one, which will have the EOF
		if (y != height - 1) fprintf(f_arte_ptr, "%c", '\n');
	}
	fclose (f_arte_ptr);
}

void frame_art(
	char *name_of_archive,
	int  height,
	int  width
) {
	FILE *f_arte_ptr = fopen(name_of_archive, "r");
	if (f_arte_ptr == NULL) {
		printf(
			"Erro na abertura do arquivo, "
			"Você esqueceu de fechar o arquivo antes? "
			"Ou deu free na string com o nome sem querer?\n"
		);

		exit(EXIT_FAILURE);
	}

	int amount_of_spaces;
	const char *support;
	if (width % 2 == 0) {
		amount_of_spaces = width / 2;
		support           = "/\\";
	} else {
		amount_of_spaces = width / 2 + 1;
		support           = "Ʌ";
	}

	for (int i = 0; i < amount_of_spaces; i++) printf(" ");
	printf("%s\n", support);

	printf("╭");
	for (int i = 0; i < width; i++) printf("—");
	printf("╮\n");

	for (int i = 0; i < height; i++) {
		printf("|");
		for (int j = 0; j < width; j++) {
			char current_pixel = fgetc(f_arte_ptr);
			printf("%c", current_pixel);
		}
		printf("|");

		char line_break = fgetc(f_arte_ptr);
		if (line_break != EOF) printf("%c", line_break);
	};
	fclose(f_arte_ptr);

	printf("\n╰");
	for (int i = 0; i < width; i++) printf("—");
	printf("╯\n");
}

char *receive_name () {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    //adicionando '\0' ao final da string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}

void show_art (char **art, int height_board, int width_board){
	int y, x;
	for (y = 0; y < height_board; y++){
		for (x = 0; x < width_board; x++){
			printf ("%c", art[y][x]);
		}
		printf ("\n");
	}
	printf ("\n");
}