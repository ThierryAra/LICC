#define tipo_dado unsigned int
#define LIMITE 10000

tipo_dado* vetor;

/*  Aloca espaco na memoria para o vetor de tamanho n        */
tipo_dado* criar_vetor(int n);

/*  Adiciona numeros na ordem crescente no vetor, de 2 ate n */
void receber_numeros(tipo_dado** vetor, int n);

/*  Para cada numero de *vetor, se verifica seus multiplos
    quando um eh encontrado, atribui-se 0 na posicao, sendo verificado
    ate a posicao 'n'. Cada numero analisado, diferente de 0, eh adicionado
    em **primos.
    PARAMETRO:
        @vetor : vetor que contem numero de 2 ate n
        @n     : tamanho de *vetor
    RETORNO:
        *primos: vetor contendo todos os primos entre 2 e n  */
tipo_dado* crivo_de_erastostenes(tipo_dado* vetor, int n);

/* Desaloca o espaco de memoria ocupado por *vetor e *primos */
void excluir_vetor(tipo_dado* vetor, tipo_dado* primos);