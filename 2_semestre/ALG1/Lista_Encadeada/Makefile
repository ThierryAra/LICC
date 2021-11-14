objects = main.c lista_e.c
executavel = run

all:
	gcc $(objects) -o $(executavel)

valgrind: all
	valgrind --leak-check=full --track-origins=yes -s ./$(executavel)

run: all
	./$(executavel)

clean:
	rm *.o $(executavel)