objects = editar_campo.o main.o
executavel = run

main.o: editar_campo.h

editar_texto.o: editar_campo.h

all: editar_campo.h
	gcc -c *.c
	gcc -o $(executavel) $(objects)

run: all
	./$(executavel)

clear:
	rm *.o $(executavel)


