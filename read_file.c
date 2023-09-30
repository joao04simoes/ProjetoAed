#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *read_file(const char *filename)
{
	FILE *fp;
	Matriz *matrix = (Matriz *)malloc(sizeof(Matriz));

	char buffer[1024], firstLine[1024]; // Buffer to read lines from the file

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Impossivel abrir o ficheiro.");
		exit(EXIT_FAILURE);
	}

	if (fgets(firstLine, sizeof(firstLine), fp) != NULL)
		sscanf(firstLine, "%d %d %d %d %d", &matrix->rows, &matrix->colu, &matrix->cordX, &matrix->cordY, &matrix->variante);
	matrix->head = NULL;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{

		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		// Allocate memory for the columns of the new row
		newNode->data = (int *)malloc(sizeof(int) * matrix->rows);
		if (!newNode->data)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		int indiRow = matrix->rows;
		newNode->indice = indiRow;
		indiRow--;
		int i = 0;
		char *token = strtok(buffer, " ");
		while (token != NULL)
		{
			newNode->data[i] = atoi(token);
			token = strtok(NULL, " ");
			i++;
		}
		if (matrix->head == NULL)
		{
			matrix->head = newNode;
			continue;
		}
		Node *aux = matrix->head, *auxT = NULL;
		while (aux != NULL)
		{
			auxT = aux;
			aux = auxT->next;
		}
		auxT->next = newNode;
	}

	fclose(fp);
	return matrix;
}