all:
	gcc -c database.c server.c
	gcc -o server.out server.o database.o
	gcc -o client.out client.c -w

run-server:
	./server.out

run-client:
	./client.out
