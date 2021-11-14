#define TAM_TEXTO 101
#define TAM_CORRIGIR 21

typedef struct dados DADOS;

/* Armazena espaco na memoria para a struct dados */
DADOS* criar_dados();

/* Recebe da entrada padrao uma sequencia de caracteres ate encontrar um \n */
char* receber_palavra();

/* Recebe da entrada padrao uma sequencia de caracteres ate encontrar um \n ou EOF */
int receber_texto(DADOS* dados);

/* Substitui sub-strings de texto */
void corrigir_texto(DADOS* dados);

/* Imprime o texto gerado por 'corrigir_texto' */
void exibir_texto_corrigido(DADOS* dados);

/* Libera o espaco armazenado para os dados da struct */
void excluir_textos(DADOS* dados);