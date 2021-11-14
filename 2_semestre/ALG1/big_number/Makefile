objects = main.c input.c big_number.c
headers = input.h big_number.h
executable = run

all:
	gcc $(objects) -o $(executable) -g

run: all
	./$(executable)

valgrind: all
	valgrind --leak-check=full ./$(executable)

zip:
	zip dic.zip $(objects) $(headers) Makefile 