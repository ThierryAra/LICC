objects = main.c editar_texto.c

all:
	gcc $(objects) -o run

run: all
	./run

valgrind: all
	valgrind --leak-check=full ./run < 2.in