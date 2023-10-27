CC = gcc #compiler

TARGET = tileblaster #target file name

all: 
	$(CC) -Wall -std=c99 -O3  -o $(TARGET)    main.c read_file.c variante1.c  gravidade.c output.c free.c newPilha.c dfs.c variante3.c thereishope.c

clean:  
	rm $(TARGET)

