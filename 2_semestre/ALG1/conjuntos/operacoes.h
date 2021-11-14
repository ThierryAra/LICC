typedef short int sint;

//Retorna um conjunto composto com a uniao dos valores dos dois conjuntos passados por referencia
sint *uniao (sint *conjunto1, sint *conjunto2);

//Retorna um conjunto composto apenas com os valores iguais nos dois conjuntos
sint *interseccao (sint *conjunto1, sint *conjunto2);

//Retorna um conjunto com os valores pertencentes ao conjunto1, que nao estejam em conjunto2
sint *diferenca (sint *conjunto1, sint *conjunto2);

//Identifica o maior valor do conjunto
sint max_valor (sint *conjunto);

//Identifica o menor valor do conjunto
sint min_valor (sint *conjunto);

//Verifica se dois conjuntos sao iguais
sint verificar_igualdade (sint *conjunto1, sint *conjunto2);

