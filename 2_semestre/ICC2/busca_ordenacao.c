/* Codigo com funcoes para busca e ordenacao
 * @author Moacir A Ponti
 * @date 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FAIL -404

/* Funcao que gera um vetor de inteiros aleatorios
	em um determinado intervalo de valores
   @param tam tamanho do vetor a ser gerado (int)
   @param min valor minimo (int)
   @param max valor maximo (int)
   @param ordenado para vetor ordenado 1, nao ordenado 0
   @return endereco do vetor na heap (int*)
*/
int* gera_vetor (int tam, int min, int max, int ordenado) {

	// verifica problemas
	if (tam < 1 || min > max) return NULL;

	int* vet = (int *) malloc(sizeof(int)*tam);

	// verifica se houve problema na alocacao
	if (vet == NULL) return NULL;
	vet[0] = (rand() % 2) + min;
	for (int i = 1; i < tam; i++) {
		// ex. min = 0, max = 5, [0, 4] = [0,4+1] = [0, 5]
		//     min = 3, max = 8, [0, 5] + 3 = [3, 8]
		if (!ordenado) {
			vet[i] = (rand()%(max-min+1)) + min;
		}
		else {
			int val = vet[i-1] + rand()%3;
			if (val > max) val = max;
			vet[i] = val;
		}
	}
	return vet;
}


/* Imprime vetor de inteiros
   @param v vetor (int*)
   @param N tamanho do vetor (int)
*/
void imprime_vetor(int*v, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");
}

/* Busca sequencial
   @param v vetor de inteiros para realizar a busca
   @param chave a ser buscada
   @param N tamanho do vetor
   @return posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_sequencial(int* v, int chave, int N) {
	for (int i = 0; i < N; i++) {   
		if (v[i] == chave)
			return i;
	}	
	return FAIL;
}

/* Busca sequencial recursiva
 * OBS: usada para fins didaticos, na pratica usar iterativa
   @param v vetor de inteiros para realizar a busca
   @param chave a ser buscada
   @param N tamanho do vetor
   @param i posicao a ser verificada
   @return posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_sequencial_recursiva(int* v, int chave, int N, int i) {

	// comparacoes - c
	// chamada da funcao - b
	// aritmeticas - a

	// 1 - caso base (criterio de parada) trivial
	//     1.a fim do vetor
	//     1.b encontrar a chave
	if (i >= N) return FAIL;				// c
	if (v[i] == chave) return i; // encontrei, retorno	// c

	// 2 - passo recursivo
	return busca_sequencial_recursiva(v, chave, N, i+1);	// a+b
								// 2c+a+b
}

/* Busca binaria recursiva
   Assume que o vetor esta ordenado
   @param v vetor de inteiros para realizar a busca
   @param chave a ser buscada
   @param ini posicao inicial do espaco de busca
   @param fim posicao final do espaco de busca
   @return posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_binaria(int* v, int chave, int ini, int fim) {
	
	// caso base 1
	if (ini > fim) return FAIL;	// c

	// calcula ponto central e verifica se chave foi encontrada
	int c = (int)((ini+fim)/2.0);  // 2a

	// caso base 2
	if (v[c] == chave) return c;   // c

	// passo recursivo
	// a. chave esta antes do centro, reduz a metade o espaco de busca
	if (chave < v[c]) 	      // c
		return busca_binaria(v, chave, ini, c-1); // a+b (nao executa no pior caso)
	
	// b. chave esta depois do centro, reduz a metade o espaco de busca
	if (chave > v[c])  // c
		return busca_binaria(v, chave, c+1, fim); // a+b

	// pior caso => c + 2a + c + c + c + a+b => 3a + 4c + b
}



/* Busca binaria iterativa
   Assume que o vetor esta ordenado
   @param v vetor de inteiros para realizar a busca
   @param chave a ser buscada
   @param ini posicao inicial do espaco de busca
   @param fim posicao final do espaco de busca
   @return posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_binaria_iterativa(int* v, int chave, int ini, int fim) {
	// 0 - caso base (busca sem sucesso)
	while (ini <= fim) {
		// calcula ponto central e verifica se chave foi encontrada
		int c = (int)((ini+fim)/2.0);
		
		//printf("%d : %d\n", c, v[c]);

		if (v[c] == chave) return c;
		// chave esta antes do centro, reduz a metade o espaco de busca
		if (chave < v[c]) fim = c-1;
		// chave esta depois do centro, reduz a metade o espaco de busca
		if (chave > v[c]) ini = c+1;
	}
	return FAIL;
}


/* Insertion sort
 * Metodo de ordenacao inplace (altera o vetor)
 * 	metodo de insercao na posicao correta
*
 * @param v vetor a ser ordenado
 * @param n tamanho do vetor
 */
void insertion_sort(int* v, int N) {

	//   vetor
	// 	[ LO | LD ]
	// 	  j   i
	//      [ 8 | 7 0 1 ]  el = 7
	//    j < 
	//      [ 8 | 8 0 1 ]  el = 7
	//      [ 7 8 | 0 1 ]  el = 7
	//
	// 	    j   i
	//      [ 7 8 | 0 1 ]  el = 0
	//        j  
	//      [ 7 8 8 | 1 ]  el = 0
	//    j <    
	//      [ 0 7 8 | 1 ]  el = 0
	
	int i = 1;

	// para cada elemento na lista desordenada
	while (i < N) {		                  // N
		int el = v[i]; // fixa elemento a ser comparado com anteriores
		int j = i-1; // indice para percorrer elementos anteriores

		// enquanto houver elementos a serem comparados e o 
		// elemento for menor do que o anterior
		while (j >= 0 && el < v[j]) {     // 1
			v[j+1] = v[j]; // movimenta valor para frente
			j--; // indice retorna uma posicao
		}
		// encontrei a posicao correta
		v[j+1] = el;

		i++;
	}
}

/* Merge sort
 * ordenacao por intercalacao - divisao e conquista
 * 	Divisao: particionar o problema até chegar num caso trivial
 * 		caso trivial da ordenacao de um vetor? um único elemento
 *
 * @param v vetor a ser ordenado
 * @param ini posicao inicial a ser ordenada
 * @param fim posicao final a ser ordenada
 */
void mergesort(int* v, int ini, int fim) {

	//  mergesort(v, 0, 7)
	//    0  1  3  4   5   6  7
	//  ini                   fim
	//
	//  mergesort(v, 0, 3)
	//   0   1  3
	// ini     fim
	//
	//  mergesort(v, 0, 1)                
	//  X  X
	//  0  1
	// 80 75   
	//ini  fim
	//
	//  mergesort(v, 0, 0) ^          mergesort(v, 1, 1)     ^
	//  0                  |          1
	// ini=fim X ok esta ordenado    ini=fim ok esta ordenado 

	// 1 - caso base (vetor de um único elemento, caso trivial)
	if (fim <= ini) return;

	// calcula posicao central
	int c = (int) (fim+ini)/2.0;

	// duas chamadas recursivas, uma para cada metade do vetor
	// 2 - passo recursivo (divisao)
	mergesort(v, ini, c);
	mergesort(v, c+1, fim);

	// agora nesse ponto eu sei que o vetor v tem:
	// v[ini : c  ] - é um vetor ordenado  ex. v[0:0]
	// v[c+1 : fim] - é um vetor ordenado  ex. v[1:1]

	// 3 - intercalacao - combinar solucoes parciais (conquista)
		
	// preciso alocar um vetor auxiliar para intercalar
	// tamanho do vetor?
	// 0 1 2 3 4 5 6 7
	// x x . .
	// 0:0 1:1
	// ini = 0
	// fim = 1  -> tam 2    1-0+1 = 2
	//
	// 2:2  3:3
	// ini = 2
	// fim = 3  -> tam 2    3-2+1 = 2
	//
	// 0:3  4:7    
	// ini = 0
	// fim = 7  -> tam 8    7-0+1 = 8
	//
	int* aux = (int*) malloc(sizeof(int) * (fim-ini+1));

	int i = ini; // indice inicial da L1 (ini -> centro)
	int j = c+1; // indice inicial da L2 (centro+1 -> fim)
	int k = 0;   // indice do vetor auxiliar (0 ate fim-ini)

	// compara elementos das duas listas (subvetores) ordenados
	// enquanto houver elementos das DUAS listas para serem comparados
	while (i <= c && j <= fim) {
		if (v[i] <= v[j]) {
			aux[k] = v[i]; // copia elemento da L1
			i++; // movo para o proximo elemento da L1
		} else {
			aux[k] = v[j]; // copia elemento da L2
			j++;
		}
		k++;
	}

	// tenho uma das listas com elementos restantes
	// copio todos os restantes da L1
	while (i <= c) {
		aux[k] = v[i];
		i++; k++;
	}
	// copio todos os elementos da L2
	while (j <= fim) {
		aux[k] = v[j];
		j++; k++;
	}

	// aux contem a intercalacao do vetor v[ini:c] e v[c+1:fim]
	// copia de aux para o vetor original
	for (i = ini, k = 0; i <= fim; i++, k++) {
		v[i] = aux[k];
	}

	free(aux);
}



int main (int argc, char* argv[]) {

	// pegar valores N, min, max da linha de comando
	// argv[0] - programa, argv[1] - N, argv[2] - min, argv[3] - max, argv[4] - verb
	if (argc < 5) {
		printf("Uso do programa: \n");
		printf(" %s <tam vetor> <val min> <val max> <verb>\n", argv[0]);
		return 1;
	}

	int N = atoi(argv[1]);	
	int min = atoi(argv[2]);	
	int max = atoi(argv[3]);	
	int verb= atoi(argv[4]);
	if (N < 1 || max <= min) {
		printf("Verifique valores informados\n");
		printf(" - tam deve ser maior do que 0\n");
		printf(" - maximo deve ser maior do que o minimo\n");
		return 2;
	}

	srand(0);
	int* v1 = gera_vetor(N, min, max, 0);

	srand(0);
	int* v2 = gera_vetor(N, min, max, 0);
	
	srand(0);
	int* v3 = gera_vetor(N, min, max, 0);
	
	//if (verb) imprime_vetor(v, N);
	if (verb) imprime_vetor(v1, N);

	printf("Dica (penultima chave): %d\n", v1[N-1]);

	int chave;
	scanf("%d", &chave);

	clock_t t1, t2;

	t1 = clock();
	// realiza busca
	int pos = busca_sequencial(v1, chave, N);
	t2 = clock();
	double ts = (t2-t1)/(double)CLOCKS_PER_SEC;

	printf("Busca sequencial:\n\t");
	if (pos >= 0) {
		printf("Chave encontrada em %d\n", pos);
	} else {
		printf("Busca sem sucesso\n");
	}

	// realiza busca binaria
	// primeiro ordena
	t1 = clock();
	mergesort(v2, 0, N-1);
	pos = busca_binaria(v2, chave, 0, N-1);
	t2 = clock();
	double tbm = (t2-t1)/(double)CLOCKS_PER_SEC;

	printf("Busca binaria merge:\n\t");
	if (pos >= 0) {
		printf("Chave encontrada em %d\n", pos);
	} else {
		printf("Busca sem sucesso\n");
	}


	// realiza busca binaria
	// primeiro ordena
	t1 = clock();
	insertion_sort(v3, N);
	pos = busca_binaria(v3, chave, 0, N-1);
	t2 = clock();
	double tbi = (t2-t1)/(double)CLOCKS_PER_SEC;

	printf("Busca binaria insertion:\n\t");
	if (pos >= 0) {
		printf("Chave encontrada em %d\n", pos);
	} else {
		printf("Busca sem sucesso\n");
	}

	printf("Tempo de processamento:\n");
	printf("Busca sequencial: %.6lf seg.\n", ts);
	printf("Busca binaria merge: %.6lf seg.\n", tbm);
	printf("Busca binaria insertion: %.6lf seg.\n", tbi);

	free(v1);
	free(v2);

	return 0;
}
