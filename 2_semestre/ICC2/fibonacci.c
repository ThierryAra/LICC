#include <stdio.h>
#include <time.h>
/*
	Recursão:
	- exemplo Fibonacci (versão iterativa versus recursiva)
	- 0 1 1 2 3 5 8 13 ...
*/

void fibonacci_iterativo(int numero){
	//Conceito: fibonacci(n) = 
	//primeiro
	//segundo
	//(primeiro)+(segundo)
	//(primeiro+segundo)+(segundo)
	//(primeiro+segundo+segundo)+(primeiro+segundo)
	
	int ultimo = 0;
	int atual = 1;
	
	int i;
	for(i=0; i<numero; i++){
		//printf("%i ", ultimo);
		int aux = ultimo;
		ultimo = atual;
		atual = atual+aux;
	}
}

void fibonacci_recursivo(int termosRestantes, int ultimo, int atual){
	if (termosRestantes >= 1){
		//printf("%i ", ultimo);
		int aux = ultimo;
		ultimo = atual;
		atual = atual+aux;
		fibonacci_recursivo(termosRestantes-1, ultimo, atual);
	}
}

int fibonacci_termo(int numero){
	if (numero == 1) return 0;
	if (numero == 2) return 1;
	return fibonacci_termo(numero-1) + fibonacci_termo(numero-2);
	
	//fibonacci(8º numero) = fibonacci(7º numero) + fibonacci(6º numero)
	
	//fibonacci (7º numero) = fibonacci(6º) + fibonacci(5º)
	//...
	
	//fibonacci(6º numero) = fibonacci(5º) + fibonacci(4º)
	//...
	
	//esta função é mais simples de implementar, porém:
	//	- recalculamos os mesmos termos diversas vezes
	//	- o custo computacional é maior que nas duas versões anteriores
}

int main(){
	int numero;
	clock_t c1, c2;
    printf("Digite um numero: ");
	scanf("%d", &numero);
	
	printf("\nFibonacci iterativo: ");
	c1 = clock();
    fibonacci_iterativo(numero);
	c2 = clock();
    double tempo = (c2-c1)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao do iterativo: %.10f\n", tempo);
    
    
    printf("\nFibonacci recursivo: ");
	c1 = clock();
    fibonacci_recursivo(numero, 0, 1);
	c2 = clock();
    tempo = (c2-c1)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao do recursivo: %.10f\n", tempo);

    /* c1 = clock();
	printf("\nFibonacci termo: %i\n", fibonacci_termo(numero));
	c2 = clock();
    tempo = (c2-c1)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execucao do termo: %f\n", tempo);
	
	for(int i = 1; i <= numero; i++)
		printf("%i ", fibonacci_termo(i)); */
		
	return 0;	
}