# call it as:
# $ make app=<applicationName>

CC = gcc
FLAGS = 

BINARY = ./build/binary

all: compile run

compile:
	$(CC) ./$(app).c -o $(BINARY) $(FLAGS)

run:
	$(BINARY)

clean:
	rm -f $(BINARY)


