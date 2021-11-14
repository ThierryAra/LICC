/* Verifica se a celula analizada eh uma bomba '*' ou nao. Caso nao seja, eh adicioado
+ 1 unidade, demonstrando que possui 1 vizinho. Caso seja, nada acontece. */
#define VIZINHO(celula, qtd_vizinhos) ((celula != '*') ? qtd_vizinhos++ : qtd_vizinhos);

typedef struct jogo JOGO;

/*  Retorna um ponteiro com espaco alocado na memoria */
JOGO* criar_campo();

/*  Recebe de um arquivo dados sobre o campo minado.
    Parametros:
        - char* nome_jogo - nome do arquivo.
    Retorno:
        - Informacoes sobre o campo minado. */
void receber_jogo(JOGO* jogo, char* nome_jogo);

/*  Adiciona a "int** dicas", as informacoes sobre os campos vizinhos de cada bomba.
    Parametros:
        - JOGO* jogo: contem "int** dicas", onde sera salvo o campo com as dicas. */
void gerar_campo_dicas(JOGO* jogo);

/*  Em cada celula de 'dicas', toda a vizinhanca (8 celulas em volta) recebera '+= 1'. 
    Parametros:
        - JOGO* jogo:  contem "int** dicas", onde serao somadas as dicas;
        - int altura:  identificacao do eixo y que contem uma bomba;
        - int largura: identificacao do eixo x que contem uma bomba; */
void adicionar_dicas(JOGO* jogo, int altura, int largura);

/*  Exibe 'int** dicas' com todas as dicas e as bombas do campo.
    Parametros:
        - JOGO* jogo: contem "int** dicas", onde sera salvo o campo com as dicas. */
void exibir_dicas(JOGO* jogo);

/*  Exibe o campo minado apenas com as bombas e espacos vazios do campo.
    Parametros:
        - JOGO* jogo: endereco que contem "char** campo". */
void imprimir_campo(JOGO* jogo);

/*  Analisa o conteudo de campo_minado(coord_y, coord_x).
    - Caso seja '*', 'exibir_dicas' sera chamado;
    - Caso seja uma dica, ela sera exibida com 'X' em todas as outras celulas;
    - Caso seja um espaco em branco, campo_recursivo sera criado e 'espaco_vazio', chamado.
    Parametros:
        - JOGO* jogo:  endereco que contem "int** dicas", onde serao somadas as dicas;
        - int coord_y: identificacao do eixo y da celula selecionada;
        - int coord_x: identificacao do eixo x da celula selecionada; */
void acao(JOGO* jogo, int coord_y, int coord_x);

/*  Recursivamente, 'int ***campo_recursivo' sera preencido com '-2' onde houver uma dica 
    e '1' onde ha um espaco vazio, verificado em "dicas" e "campo", analisando 
    cada vizinho da celula campo_recursivo[coord_y][coord_x].
    Parametros:
        - JOGO* jogo:       endereco que contem "int** dicas" e "char** campo"
        - int coord_y:      identificacao do eixo y da celula sendo analizada;
        - int coord_x:      identificacao do eixo x da celula sendo analizada;
        - int*** campo_recursivo: endereco da matriz a ser alterada na funcao. */    
void espaco_vazio(JOGO* jogo, int coord_y, int coord_x, int*** campo_recursivo);

/*  Exibe 'int ***campo_recursivo':
    - Onde houver '-2' sera exibido a dica (retirada de "int** dicas")
    - Onde houver '1' sera exibido '.' -> celula vazia
    - Onde houver '0', sera exibido 'X' -> celula desconhecida
    Parametros:
        - JOGO* jogo:       endereco que contem "int** dicas";
        - int*** campo_recursivo: endereco da matriz a ser exibida na funcao. */    
void exibir_campo_recursivo(JOGO* jogo, int*** campo_recursivo);

/*  Da free em todas os ponteiros da struct */
void excluir_tabuleiro(JOGO* jogo);