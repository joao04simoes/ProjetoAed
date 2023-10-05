CC = gcc #compiler

TARGET = tileblaster #target file name

all: 
	$(CC) -Wall -std=c99 -O3  -o $(TARGET)    main.c read_file.c variante1.c pilha.c variante2.c output.c free.c

clean:  
	rm $(TARGET)



