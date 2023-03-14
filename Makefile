all: clean server client
	@./server

server:
	@gcc src/server.c -I lib -o server

client:
	@gcc src/client.c -I lib -o client

clean:
	@rm -rf server
	@rm -rf client
	@rm -rf a.out
	@clear