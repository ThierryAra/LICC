objects = main.c editar_lista.c
executavel = run

all:
	gcc $(objects) -o $(executavel)

valgrind: all
	valgrind --leak-check=full --track-origins=yes -s ./$(executavel) < 3.in

run: all
	./$(executavel)

clean:
	rm *.o $(executavel)