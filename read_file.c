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
		sscanf(firstLine, "%d %d %d %d %d", &matrix->rows, &matrix->colu, &matrix->variante, &matrix->cordX, &matrix->cordY);
	matrix->head = NULL;
	int indicolu = 1;

	for (int i = 0; i < matrix->colu; i++)
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
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->indice = indicolu;
		indicolu++;
		//int i = 0;
		if (matrix->head == NULL)
		{
			matrix->head = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
			continue;
		}
		Node *aux = matrix->head, *auxT = NULL;
		while (aux != NULL)
		{
			auxT = aux;
			aux = auxT->next;
		}
		auxT->next = newNode;
		newNode->prev = auxT;
	}

	int i = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{

		printf("loop linhas\n");
		char *token = strtok(buffer, " ");
		Node *aux = matrix->head, *auxT = NULL;

		for (int j = 1; j <= matrix->colu; j++) //se estamos a por em cada posição do vetor os numeros das colunas nao deviamos ter l <= matrix->rows, acaba por ser o mesmo.
		{
			printf("novo dado %d\n", atoi(token));
			aux->data[i] = atoi(token);
			auxT = aux->next;
			aux = auxT;
			token = strtok(NULL, " ");
		}
		i++;
	}

	fclose(fp);
	return matrix;
}
