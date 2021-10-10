#include<stdio.h>
#include<stdlib.h>  
#include<assert.h>
#include<string.h>
#include<math.h>
#include<complex.h>

#include<time.h>

char* receber_string();
unsigned char* read_wav_data(char* fname, int* lenght);
double complex* DFT(unsigned char *audio, int length, int* coeficientes_negativos);
void ordernar_dados(double* magnitude, int length);
double* converter_imaginario(double complex* dados, int length, int n);
void desordernar_dados(double* magnitude, int length);
double complex* DFT_inv(double* desordenado, int length);
void imprimir_sequencia(double* imaginario_convertido, int n);

void ordenar_merge(double* magnitude, int ini, int fim){
    if (fim == ini + 1) return;

	// calcula posicao central
	int c = (int)((fim + ini) / 2.0);

	ordenar_merge(magnitude, ini, c);
	ordenar_merge(magnitude, c+1, fim);

	double* aux = (double*) malloc(sizeof(double) * (fim-ini+1));

	int i = ini;
	int j = c+1;
	int k = 0;

	while (i <= c && j <= fim) {
		if (magnitude[i] >= magnitude[j]) {
			aux[k]     = magnitude[i]; // copia elemento da L1
            aux[k + 1] = magnitude[i + 1];
			i += 2; // movo para o proximo elemento da L1
		} else {
			aux[k]     = magnitude[j]; // copia elemento da L2
			aux[k + 1] = magnitude[j + 1];
            j += 2;
		}
		k += 2;
	}

	// tenho uma das listas com elementos restantes
	// copio todos os restantes da L1
	while (i <= c) {
		aux[k]     = magnitude[i];
        aux[k + 1] = magnitude[i + 1];
		i += 2; k += 2;
	}
	// copio todos os elementos da L2
	while (j <= fim) {
		aux[k]     = magnitude[j];
        aux[k + 1] = magnitude[j + 1];
		j += 2; k += 2;
	}

	// aux contem a intercalacao do vetor magnitude[ini:c] e magnitude[c+1:fim]
	// copia de aux para o vetor original
	for (i = ini, k = 0; i <= fim; i++, k++) {
		magnitude[i]     = aux[k];
	}

	free(aux);
}


int main(int argc, char const *argv[]){
    char* nome_arquivo;
    nome_arquivo = receber_string();    
    
    int n_coeficientes;
    scanf("%d", &n_coeficientes);

    //recebendo os dados
    int length;
    unsigned char* audio  = read_wav_data(nome_arquivo, &length);
    free(nome_arquivo);
    
    printf("%d\n", length); //saida 1

    //transformando os dados em numeros complexos
    int coeficientes_negativos = 0;
    double complex* dados = DFT(audio, length, &coeficientes_negativos);
    free(audio);
    
    printf("%d\n", coeficientes_negativos); //saída 2

    //convertendo os numeros imaginarios em reais e ordenando o vetor
    double* novo_complex = malloc(n_coeficientes * sizeof(double));
    double* imaginario_convertido = converter_imaginario(dados, length, n_coeficientes);
    free(dados);

    //desordenando o vetor
    desordernar_dados(imaginario_convertido, length);

    //gerando novos imaginarios para o novo audio
    //double complex* novo_audio = DFT_inv(imaginario_convertido, n_coeficientes);
    free(imaginario_convertido);
    
    free(novo_complex);
    //free(novo_audio);
    return 0;
}

char* receber_string(){
    char* texto = NULL;
    char caracter;

    int c = 0;

    caracter = getchar();
    while(caracter != '\n'){
        texto = realloc(texto, (c + 1) * sizeof(char));

        texto[c] = caracter;
        caracter = getchar();
        c++;
    }

    //adicionando \0
    texto = realloc(texto, (c + 1) * sizeof(char));
    texto[c] = '\0';

    return texto;
}

unsigned char* read_wav_data(char* fname, int* length) {
    assert(fname != NULL);
    FILE* fp = fopen(fname, "rb");
    if(fp == NULL)
        printf("erro");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    int dataSize = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;

    unsigned char* data = malloc(sizeof(*data) * (dataSize));
    printf("%d\n\n", dataSize);
    (*length) = (dataSize);

    int i = 0;
    while (i < dataSize) {
        fread(&data[i++], sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
    
    return data;
}

double complex *DFT(unsigned char *audio, int length, int* coeficientes_negativos) {
    assert(audio != NULL);
    double complex *coef = (double complex *) calloc(length, sizeof(double complex));

    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++) {
            coef[k] += audio[n] * cexp((-2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
        //printf("%.1lf + %.1lfi\n", creal(coef[k]), cimag(coef[k]));
        if(creal(coef[k]) <= 0 && cimag(coef[k]) <= 0)
            (*coeficientes_negativos)++;
    }
    return coef;
}

double* converter_imaginario(double complex* dados, int length, int n){
    assert(dados != NULL);

    double* magnitude = malloc((length * 2) * sizeof(double));
    
    //calculando a magnitude de cada numero complexo
    for (int i = 0, k = 0; k < length; i += 2, k++){
       magnitude[i]     = sqrt(pow(creal(dados[k]), 2) + pow(cimag(dados[k]), 2));
       magnitude[i + 1] = k; //posicao
    }
    
    //ordenando o vetor
    clock_t c1, c2;
    c1 = clock();
    //ordernar_dados(magnitude, length*2);
    ordenar_merge(magnitude, 0, (length * 2) - 1);
    c2 = clock();
    printf("TEMPO EXECUCAO: %lf", (c2-c1)/(double)CLOCKS_PER_SEC);
    //zerando os (total - n) termos
    for (int i = (n * 2) - 2; i < length * 2; i += 2)
        magnitude[i] = 0;

    //imprimindo os primeiros T valores ordenados (saida 3)
    imprimir_sequencia(magnitude, n);
    return magnitude;
}

void ordernar_dados(double* magnitude, int length){
    for (int i = 2; i < length * 2; i += 2) { 
        double num = magnitude[i];
        double pos = magnitude[i + 1];
		
		int j = i - 2;
	
		while (j >= 0 && num > magnitude[j]) {

			magnitude[j + 2] = magnitude[j];
            magnitude[j + 3] = magnitude[j + 1];
			j -= 2;
		}
        magnitude[j + 2] = num;
        magnitude[j + 3] = pos;
	}
}

void desordernar_dados(double* magnitude, int length){
    //voltando os valores para ordem (posicoao) original
    for (int i = 3; i < length * 2; i += 2) { 
        double pos = magnitude[i];
        double num = magnitude[i - 1];
		
		int j = i - 2;
	
		while (j >= 1 && pos < magnitude[j]) {
			magnitude[j + 2] = magnitude[j];
            magnitude[j + 1] = magnitude[j - 1];
			j -= 2;
		}
        
        magnitude[j + 2] = pos;
        magnitude[j + 1] = num;
	}
    /* printf("DESORDENADO\n");
    for (int i = 0; i < length * 2; i += 2)
    {
        printf("pos: %f num: %f\n", magnitude[i + 1], magnitude[i]);
    } */
}

double complex *DFT_inv(double* desordenado, int length) {
    assert(desordenado != NULL);
    double complex *coef = (double complex*)calloc(length, sizeof(double complex));

    for (int n = 0; n < length; n++) {
        for (int k = 0; k < length; k++) {
            coef[n] += desordenado[k] * cexp((-2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
        coef[n] = coef[n] / length;
        //printf("%.1lf + %.1lfi\n", creal(coef[k]), cimag(coef[k]));
    }
    return coef;
}

void imprimir_sequencia(double* novo_complex, int n){
    for (int i = 0; i < (n * 2); i += 2)
        printf("%d\n", (int)novo_complex[i]);
}