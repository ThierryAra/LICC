/*  Audio Compression
    Thierry de Souza Araujo - 12681094
    USP - São Carlos - ICMC
    Introducao a Ciencia da Computacao II (SCC0201) */

#include<stdio.h>
#include<stdlib.h>  
#include<assert.h>
#include<string.h>
#include<math.h>
#include<complex.h>

typedef struct value{
    double complex coefficient;
    double magnitude;
    int original_position;
}VALUE;


/*  Reads the audio data from a .wav file.
    PARAMETERS:
        fname : name of the file to be read
        length: gets the size of the array that will be returned */
unsigned char* read_wav_data(char* fname, int* lenght);

void DFT(unsigned char *audio_data, VALUE* audio, int length, int* negative_coefficients);

/*  From the coefficients, the magnitude of each data position is calculated
    PARAMETERS:
        audio : array with complex values
        lenght: size of the data array
        n     : initial position that must be zeroed                       */
void generate_magnitude(VALUE* audio, int length, int n);

/*  Sorts the magnitude values
    PARAMETERS:
        audio : array containing the magnitude values
        length: size of the array                   */
void sort_magnitude(VALUE* audio, int length);

/*  Sorts the array using original_position
    PARAMETERS:
        audio : array containing the data converted to double
        length: size of the audio                             */
void sort_positions(VALUE* audio, int length);

/*  Resets the coefficients from n to length to generate the new audio
    PARAMETERS:
        audio : array containing coefficients
        n     : position where the zeros will start
        length: data length                                            */
void zeroing_k_coefficients(VALUE* audio, int k, int length);

/*  It performs the inverse DFT process, thus generating complex number 
    that will generate the new audio                                   */
unsigned char* DFT_inverted(VALUE* audio, int length);

/*  Print 'length' values */
void print_sequence(VALUE* audio, int n);

/*  Produces a new audio file, similar to the first, but with less effective data
    PARAMETERS:
        new_audio: have the data for the new audio
        file_name: name of the original audio
        data_size: new_audio length                                             */
void create_new_audio(unsigned char* new_audio, char* file_name, int data_size);

int main(){
    char file_name[11];
    scanf("%s", file_name);
    
    int n_coefficients;
    scanf("%d", &n_coefficients);

    //receiving the data
    int length;
    unsigned char* audio_data = read_wav_data(file_name, &length);
    assert(audio_data != NULL);

    printf("%d\n", length); //output 1

    VALUE* audio = malloc(length * sizeof(VALUE));
    assert(audio != NULL);

    //transforming data into complex numbers
    int negative_coefficients = 0;
    DFT(audio_data, audio, length, &negative_coefficients);
    free(audio_data);
    
    printf("%d\n", negative_coefficients); //output 2

    //converting the imaginary numbers into real numbers and sorting the array
    generate_magnitude(audio, length, n_coefficients);

    zeroing_k_coefficients(audio, n_coefficients, length);

    //reordering the array 
    sort_positions(audio, length);

    //generating new imaginaries for the new audio
    unsigned char* new_audio = DFT_inverted(audio, length);
    assert(new_audio != NULL);

    create_new_audio(new_audio, file_name, length);

    free(audio);
    free(new_audio);


    system("explorer.exe teste");
    return 0;
}

unsigned char* read_wav_data(char* fname, int* length) {
    assert(fname != NULL);
    FILE* fp = fopen(fname, "rb");
    assert(fp != NULL);

    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    int dataSize = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;

    unsigned char* data = malloc(sizeof(*data) * (dataSize));
    (*length) = (dataSize);

    int i = 0;
    while (i < dataSize) {
        fread(&data[i++], sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
    
    return data;
}

void DFT(unsigned char* audio_data, VALUE* audio, int length, int* negative_coefficients) {
    assert(audio_data != NULL);
    assert(audio != NULL);
    double complex coef = 0;

    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++) {
            coef += audio_data[n] * cexp((-2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
        //printf("%.1lf + %.1lfi   ", creal(coef[k]), cimag(coef[k]));
        if(creal(coef) <= 0 && cimag(coef) <= 0)
            (*negative_coefficients)++;

        audio[k].coefficient = coef;
        coef = 0;
    }
}

void generate_magnitude(VALUE* audio, int length, int n){
    assert(audio != NULL);

    //calculating the magnitude of each complex number
    for (int i = 0, k = 0; k < length; i += 2, k++){
       audio[k].magnitude = sqrt(pow(creal(audio[k].coefficient), 2) + pow(cimag(audio[k].coefficient), 2));
       audio[k].original_position = k;
    }
    
    //sorting the array
    sort_magnitude(audio, length);

    //printing the first T ordered values (output 3)
    print_sequence(audio, n);
}

void zeroing_k_coefficients(VALUE* audio, int k, int length){
    assert(audio != NULL);

    for (int i = k; i < length; i++)
        audio[i].coefficient = 0;
}

void sort_magnitude(VALUE* audio, int length){
    assert(audio != NULL);
    for(int i = 1; i < length; i++){
        VALUE value = audio[i];
        int j;

        j = i - 1;

        while(j >= 0 && value.magnitude > audio[j].magnitude) {
            audio[j + 1] = audio[j];
            j--;
        }

        audio[j + 1] = value;
    }
}

void sort_positions(VALUE* audio, int length){
    assert(audio != NULL);
    for(int i = 1; i < length; i++){
        VALUE value = audio[i];
        int j;

        j = i - 1;

        while(j >= 0 && value.original_position < audio[j].original_position) {
            audio[j + 1] = audio[j];
            j--;
        }

        audio[j + 1] = value;
    }
}

unsigned char* DFT_inverted(VALUE* audio, int length) {
    assert(audio != NULL);
    double complex coef = 0.0;
    unsigned char* wav_data = (unsigned char*)malloc(length * sizeof(unsigned char));
    assert(wav_data != NULL);

    for (int n = 0; n < length; n++) {
        for (int k = 0; k < length; k++) {
            coef += audio[k].coefficient * cexp((2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        }
        coef = coef / length;
        //printf("%.1lf + %.1lfi\n", creal(coef[k]), cimag(coef[k]));

        wav_data[n] = (unsigned char)(creal(coef));
        coef = 0.0;
    }

    return wav_data;
}

void create_new_audio(unsigned char* wav_data, char* file_name, int data_size){
    assert(wav_data != NULL);
    assert(file_name != NULL);

    FILE* audio = fopen(file_name, "rb");
    assert(audio != NULL);
    
    unsigned char header[44];
    fread(header, 1, sizeof(header), audio);
    fclose(audio);

    FILE* compressed_audio;
    compressed_audio = fopen("teste.wav", "wb");
    assert(compressed_audio != NULL);

    //first 44 bytes of the header
    fwrite(header, sizeof(unsigned char), 44, compressed_audio);

    //audio data
    fwrite(wav_data, sizeof(unsigned char), data_size, compressed_audio);

    fclose(compressed_audio);
}

void print_sequence(VALUE* audio, int n){
    assert(audio != NULL);
    
    for (int i = 0; i < n; i++)
        printf("%d\n", (int)audio[i].magnitude);
}