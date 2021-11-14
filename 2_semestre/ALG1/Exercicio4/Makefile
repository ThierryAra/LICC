objects = main.c editar_fila.c
executavel = run

all:
	gcc $(objects) -o $(executavel)

run: all
	valgrind ./$(executavel) < 2.in