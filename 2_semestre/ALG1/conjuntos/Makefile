main: main.o editar_conjunto.o operacoes.o
	gcc -o main main.o editar_conjunto.o operacoes.o -g
main.o: operacoes.h editar_conjunto.h
editar_conjunto.o: editar_conjunto.h
operacoes.o: operacoes.h editar_conjunto.h