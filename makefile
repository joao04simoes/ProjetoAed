CC = gcc #compiler

TARGET = tileblaster #target file name

all: 
	$(CC) -Wall -std=c99 -O3  -o $(TARGET)    main.c read_file.c variante1.c pilha.c gravidade.c output.c free.c pilhadfs.c dfs.c

clean:  
	rm $(TARGET)

