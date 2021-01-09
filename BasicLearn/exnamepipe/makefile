.PHONY:all
all:mkfifo server client

mkfifo:mkfifo.c
	gcc -o mkfifo mkfifo.c

server:server.c
	gcc -o server server.c

client:client.c
	gcc -o client client.c

.PHONY:clean
clean:
	rm -f mkfifo server client

