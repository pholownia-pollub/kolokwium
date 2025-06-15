all: manager worker main

manager:
	gcc -c manager.c
	ar rs libmanager.a manager.o

worker:
	gcc -c worker.c
	ar rs libworker.a worker.o

main:
	gcc -c main.c
	gcc -o projekt main.o libmanager.a libworker.a

clean:
	rm -f *.o *.a projekt

