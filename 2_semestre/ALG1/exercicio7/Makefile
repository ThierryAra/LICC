objects = main.c polynomial.c
headers = polynomial.h
executavel = run

all:
	gcc $(objects) -o $(executavel) -g

run: all
	./$(executavel) 
	
valgrind: all
	valgrind --track-origins=yes ./$(executavel)

zip:
	zip polynomial.zip $(objects) $(headers) Makefile