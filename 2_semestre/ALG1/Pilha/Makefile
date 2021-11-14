objects = editar_pilha.o main.o

all: $(objects)
	gcc -o teste $(objects) -g

editar_pilha.o: editar_pilha.h
main.o: editar_pilha.h

clean:
	rm *.o teste