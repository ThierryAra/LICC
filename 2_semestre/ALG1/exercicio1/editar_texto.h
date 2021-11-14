typedef struct dados dados_t;

/*  Cria, inicializa e retorna um ponteiro do tipo dados_t */
dados_t* criar_dado();

/*  Recebe frases da entrada (stdin) ate encontrar um numero
    Parametros: 
        @dado: struct com contem as informacoes sobre a frase recebida
        @k   : variavel que indicara quantas palavras serao exibidos em imprimir_resultado */
int receber_texto(dados_t** dado, int* k);

/*  Para cada palavra no texto, eh contado as vezes que ela se repete,
    anulando as suas reaparicoes */
void contar_repeticao(dados_t** dado);

/* Ordena as palavras de acordo com a quantidade das suas aparicoes na frase */
int ordenar_vetor_qtd(dados_t* dado);

/* Depois de ordenado por repeticao, as palavras sao ordenadas por ordem alfabetica */
int ordenar_vetor_letra(dados_t* dado);

/* Exibe as 'k' primeiras palavras do vetor ordenado */
void imprimir_resultado(dados_t* dado, int k);

/* Exclui a struct e limpa a memoria armazenada para todos os ponteiros */
void excluir_dados(dados_t* dado);