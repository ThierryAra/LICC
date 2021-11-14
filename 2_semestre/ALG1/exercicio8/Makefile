objects = main.c memory_bank.c person.c
headers = memory_bank.h person.h
executavel = run

all:
	gcc $(objects) -o $(executavel) -g

run: all
	./$(executavel)

valgrind: all
	valgrind --track-origins=yes ./$(executavel) < 1.in

zip:
	zip memory_bank.zip $(objects) $(headers) Makefile