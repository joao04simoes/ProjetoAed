CC = gcc #compiler

TARGET = tileblaster #target file name

all: 
	$(CC) -Wall -O3 -g -o $(TARGET) -x c  main.c read_file.c

clean:  
	rm $(TARGET)



