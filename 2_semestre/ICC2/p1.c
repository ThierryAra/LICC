//Thierry de Souza Araujo - 12681094
//Introducao a Ciencia da Computacao II

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

unsigned int* search_and_count(int** matriz, int* vetor, int m, int z) {
	int i, j, k, k2, el;
	unsigned int* con = calloc(z, sizeof(unsigned int));
	for (k = 0; k < z; k++) {			      //todas operacoes abaixo ocorrem z vezes
	    el = vetor[k];				
	    for(i = 0; i < m; i++){			   	   //todas operacoes abaixo ocorrem m vezes
			for(j = 0; j < m; j++){		       //todas operacoes abaixo ocorrem m vezes
		    	if (matriz[i][j] == el){       //1c * m² * z
					k2 = 0;
					while (k2 < z) {	  	   //todas operacoes abaixo ocorrem z vezes
						if (vetor[k2] == el) { //1c * m² * z²
							con[k2]++;		   //1a * m² * z²
						}	
						k2++;				   //1a * m² * z²
					}						   //----------------------------------------
		    	}							   //f(m) = (1c * m² * z²) + (1a * m² * z²) + (1a * m² * z²)
			}   							   //     = (1c * m² * z²) + 2(a * m² * z²)
	    }			  					       //f(m) = ((c * z²) + 2(a * z²)) * m²
	}				
	return con;	
}

void search_and_count_optimized(int** matriz, int* vetor, int* con, int m, int k) {
	if(k == -1)
	    return;
	
	int i, j, el;
    el = vetor[k];				
    for(i = 0; i < m; i++){			   
		for(j = 0; j < m; j++){		   
	    	if (matriz[i][j] == el){ // c * m²                                                      
				con[k]++;		     // a * m²                                                    
	    	}		                 //-------------------------  se f(-1) = 1                     
		}   						 //g(m) = (a * m²) + (c * m²) + f(k - 1)                      
									 //     = (a * m²) + (c * m²) + (a * m²) + (c * m²) + f(k - 2)   
    }								 //     = 2(a * m²) + 2(c * m²) + f(k - 2)
									 //     ...               
									 //     = n(a * m²) + n(c * m²) + f(k - n)            
									 //     	para (k - n) == -1 -> n ==  k + 1
									 //     = (k + 1)(a * m²) + (k + 1)(c * m²) + f(-1)
									 //     = k*a*m² + a*m² + k*c*m² + c*m² + 1
									 //     = (k*a + a + k*c + c) * m² + 1  -> k == z
									 //g(m) = (z*a + a + z*c + c) * m² + 1     
    search_and_count_optimized(matriz, vetor, con, m, k - 1);
}

int** alloc_matrix(int m) {
	int **mat = malloc(sizeof(int*)*m);
	srand(m);
	
	int in = 0;
	// aloca matriz ordenada
	for (int i = 0; i < m; i++) {
		mat[i] = malloc(sizeof(int)*m);
	    	for (int j = 0; j < m; j++) {
			if (i == j) in+= (rand()%3)+1;
			else in += rand()%3;
			mat[i][j] = in;
		}
	}
	// desordena matriz triangular superior
	for (int i = 0; i < m-2; i++) {
	    	for (int j = i+1; j < m-1; j++) {
			int swaps = (int)((m-j)/2.0)+1;
			for (int t = 1; t <= swaps; t++) {
				int a = (rand()%(m-j))+j;
				int b = (rand()%(m-j))+j;
				int tmp = mat[i][a];
				mat[i][a] = mat[i][b];
				mat[i][b] = tmp;
			}
		}

	}
	return mat;
}

void print_matrix(int** v, int m){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			printf("%.2d ", v[i][j]);
		}
		printf("\n");
	}
	
}

void print_vector(int* v, int m){
		printf("\n");
		for (int j = 0; j < m; j++){
			printf("%.2d ", v[j]);
		}
		printf("\n");
	
}


int* alloc_vec(int z) {
	int *vet = malloc(sizeof(int)*z);
	srand(z);
	vet[0] = rand()%2;
	for (int i = 1; i < z; i++) {
		vet[i] = vet[i-1]+(rand()%9)+1;
	}
	return vet;
}


int main () {

	int m;
	int z;
	scanf("%d", &m);
	scanf("%d", &z);

	int** mat = alloc_matrix(m);
	//print_matrix(mat, m);
	int* vet  = alloc_vec(z);
	//print_vector(vet, z);
	
	int* c = calloc(z, sizeof(unsigned int));
	search_and_count_optimized(mat, vet, c, m, z);

	for (int i = 0; i < z; i++) printf("%hu ", c[i]);
	printf("\n");

	for (int i = 0; i < m; i++) free(mat[i]);
	free(mat);
	free(vet);

	return 0;
}