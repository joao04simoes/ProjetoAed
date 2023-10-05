#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

int main(int argc, char *argv[])
{
	Matriz *matrix;
	FILE *fp, *fs;
	char firstLine[100];
	Node *aux, *auxT;
	if (argc != 2)
	{
		return 0;
	}

	const char *filename = argv[1]; // guarda o nome do ficheiro
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(0);
	}
	fs = output(filename);
	while (fgets(firstLine, sizeof(firstLine), fp) != NULL)
	{

		matrix = read_file(filename, fp, firstLine); // chamar a função de leitura do ficheiro
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

		if (matrix->variante == 1)
		{
			matrix = variante1(matrix);
			while (!isEmpty())
				pop();
		}
		if (matrix->variante == 2)
		{
			matrix = GravidadeVertical(matrix);
			matrix = GravidadeHorizontal(matrix);
		}
		escreverFicheiro(matrix, fs);

		freeMatriz(matrix);
	}
	fclose(fp);
	fclose(fs);

	return 0;
}
