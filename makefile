CC = gcc #compiler

TARGET = tileblaster #target file name

all: 
	$(CC) -Wall -std=c99 -g  -o $(TARGET)    main.c read_file.c variante1.c pilha.c gravidade.c output.c free.c newPilha.c dfs.c

clean:  
	rm $(TARGET)

