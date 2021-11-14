#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int* preencher_vetor_ordenado(int qtd){

    int *vetor = malloc (qtd * sizeof(int));
    srand(time(NULL));

    vetor[0] = 1;
    for (int i = 1; i < qtd; i++)
        vetor[i] = vetor[i - 1] + (rand() % 20);

    return vetor;
}

int* preencher_vetor_desordenado(int qtd){
    int *vetor = malloc (qtd * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < qtd; i++)
        vetor[i] = rand() % 10;

    return vetor;
}

/* A ordenacao acontece comparando 1 valor com os anteriores, 1 por 1.
Se for menor, o valor anterior eh replicado pra frente, no final, o valor
q estava sendo comparado (guardado em chave), eh adicionado na ultima posicao */
void insertion_sort(int* vetor, int qtd){
    for(int i = 1; i < qtd; i++) {
        int chave = vetor[i];
        
        int j = i - 1;
        while(chave < vetor[j] && j >= 0) {
            vetor[j + 1] = vetor[j];
            j -= 1;
        }

        vetor[j + 1] = chave;
    }
}

/* A cada busca, eh encontrado um valor central e comparado com o valor
    procurado, assim, se for maior, eh pego o valor central da primeira metade;
    E assim em diante, ate chegar em 1 unico valor ou encontrar o valor*/
int busca_binaria (int** vetor, int qtd, int num){

    int ini = 0, fim = qtd, meio;

    while (ini <= fim) {
        meio = (int) (ini + fim)/(2.0);
        
        if ((*vetor)[meio] == num)
            return meio;
        
        if (num > (*vetor)[meio]){
            ini = meio + 1;
        } else if (num < (*vetor)[meio]){
            fim = meio - 1;
        }
    }
    return 0;
}

void mergesort(int* v, int ini, int fim);

int main (int argc, char* argv[]){
    if (argc < 3){
        printf("Faltando argumentos:\n");
        printf("    1 - Numero a ser procurado\n");
        printf("    2 - Quantidade de valores no vetor\n");
        return 1;
    }

    int qtd = atoi(argv[2]);
    if (qtd > 10000 || qtd < 10){
        printf("Indique um numero valido (10 < x < 10.000)\n");
        return 1;
    }

    int *vet;
    //vet = preencher_vetor_ordenado(qtd);
    vet = preencher_vetor_desordenado(qtd);

    insertion_sort(vet, qtd);
    
    int num = atoi(argv[1]);
    int encontrado = busca_binaria(&vet, qtd, num);

    if (encontrado == 0)
        printf ("\nO numero %d nao esta no vetor!\n", num);
    else    
        printf ("\nNumero encontrado na posicao %d\n", encontrado);

    free(vet);
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
