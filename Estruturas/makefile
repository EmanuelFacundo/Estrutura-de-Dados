all: estruturas

estruturas: main.o qxdsorting.o
	gcc main.o qxdsorting.o -o estruturas

qxdsorting.o: qxdsorting.c qxdsorting.h
	gcc -c qxdsorting.c

main.o: main.c
	gcc -c main.c

clean:
	rm estruturas *.o
	
	