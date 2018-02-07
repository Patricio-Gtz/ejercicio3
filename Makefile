#HEADERS = funciones.h

default: tarea3.out

tarea3.o: tarea3.c #$(HEADERS)
	gcc -c tarea3.c -o tarea3.o

tarea3.out: tarea3.o
	gcc tarea3.o -o tarea3.out

clean:
	-rm -f tarea3.o
	-rm -f tarea3.out
