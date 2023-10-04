#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

int main(int argc, char *argv[])
{
	Matriz *matrix;
	FILE *fp, *fs;
	Node *aux, *auxT;
	char firstLine [1024];
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return EXIT_FAILURE;
	}

	const char *filename = argv[1]; // guarda o nome do ficheiro
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Impossivel abrir o ficheiro.");
		exit(EXIT_FAILURE);
	} 
	fs = output(filename);
	
	while (fgets(firstLine, sizeof(firstLine), fp) != NULL)
	{
		printf(" linhaaaaa ---- %s\n",firstLine);
		matrix = read_file(filename,fp,firstLine); // chamar a função de leitura do ficheiro
		//Node *aux = matrix->head, *auxT;
		if (matrix->variante == 1)
		{
			matrix = variante1(matrix);
			while(!isEmpty())
				pop();

		}
		if(matrix->variante == 2)
		{
			matrix = GravidadeVertical(matrix);
			matrix = GravidadeHorizontal(matrix);
			
		}
		escreverFicheiro(matrix,fs);
		for (int i = 0; i < matrix->rows; i++)
		{
		aux = matrix->head;
		while (aux != NULL)
		{
			printf("%d ", aux->data[i]); // a tabela esta a aprecer invertida primeira linha é a coluna
			auxT = aux->next;
			aux = auxT;
		}
		printf("\n");
		}

		//função free 
	}


	


	return 0;
}
