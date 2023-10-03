#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

int main(int argc, char *argv[])
{
	Matriz *matrix;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return EXIT_FAILURE;
	}

	const char *filename = argv[1]; // guarda o nome do ficheiro

	matrix = read_file(filename); // chamar a função de leitura do ficheiro
	Node *aux = matrix->head, *auxT;
	if (matrix->variante == 1)
	{
		matrix = variante1(matrix);
	}

	while (aux != NULL)
	{

		for (int i = 0; i < matrix->colu; i++)
		{
			printf("%d ", aux->data[i]); // a tabela esta a aprecer invertida primeira linha é a coluna
		}
		printf("\n");
		auxT = aux->next;
		aux = auxT;
	}

	return 0;
}
