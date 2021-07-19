#include<stdio.h>
#include<stdlib.h>

int main () {

    int *vetorHeap, n; //n2, n3;

    printf ("Quantidade de posicoes: ");
    scanf (" %i", &n);

    *vetorHeap = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        *(vetorHeap + i) = i * 10; 
    }
    for (int i = 0; i < n; i++)
    {
        printf ("%i ", *(vetorHeap + i));
    }
    free(vetorHeap);
    
//     printf ("Nova quantidade de posicoes: ");
//     scanf (" %i", &n2);

//     *vetorHeap = realloc (vetorHeap, (n2 * sizeof(int)));
//     // *vetorHeap = realloc (NULL, (n2 * sizeof(int))); -> igual ao malloc
//     // *vetorHeap = realloc (vetorHeap, NULL); -> limpa a memória
//     for (int i = 0; i < n2; i++)
//     {
//         printf (" %i", *(vetorHeap + i));
//     }

//     printf ("Terceira nova quantidade de posicoes: ");
//     scanf (" %i", &n3);
//     //posicoes no vetorHeap inicializados com 0
//     *vetorHeap = calloc (n3, sizeof(int));
//     for (int i = 0; i < n; i++)
//     {
//         printf (" %i", *(vetorHeap + i));
//     }

//     free(vetorHeap);


//     printf ("-------------------------------------------");
//     printf ("Matrizes dinamicas: \n\n");

//     int qtd_linhas, qtd_col, nqtd_linhas, nqtd_col;

//     printf ("Quantidade de linhas: ");
//     scanf (" %i", &qtd_linhas);
//     printf ("Quantidade de colunas: ");
//     scanf (" %i", &qtd_col); 

//     int **matrizHeap = malloc(qtd_linhas * sizeof(void *)); //quantidade de vetores
// 	for (int j = 0; j < qtd_col; j++)
// 		matrizHeap[j] = malloc(qtd_col * sizeof(int)); //definindo o tamanho do vetor
	
// 	//alocando i * j nas posicoes
// 	for(int i = 0; i < qtd_linhas; i++){
// 		for(int j = 0; j < qtd_col; j++)
//             *(matrizHeap[i] + j) = i * j;
// 	}

//     printf ("Atribuidos: \n");
//     for(int i = 0; i < qtd_linhas; i++){
// 		for(int j = 0; j < qtd_col; j++)
//             printf ("%i\t", matrizHeap[i] + j); //matrizHeap[i] + j == matrizHeap[i][j]
// 		printf("\n");
// 	}

//     //realloc na matriz
//     printf ("\nNova quantidade de linhas: ");
//     scanf ("%i", nqtd_linhas);
//     printf ("\nNova quantidade de colunas: ");
//     scanf ("%i", nqtd_col);

//     for(int i = 0; i < nqtd_linhas; i++){
// 		for(int j = 0; j < nqtd_col; j++){
//             if (i < qtd_linhas)
//                 *matrizHeap[i] = realloc(matrizHeap[i], nqtd_col * sizeof(int));
//             else {
//                 **matrizHeap = malloc(qtd_linhas * (nqtd_col * sizeof(int)));
//                 break;
//             }
//         }
// 		printf("\n");
// 	}
//  free (matrizHeap);


     return 0;
 }