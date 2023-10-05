#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *read_file(const char *filename, FILE *fp, char *firstLine)
{

	Matriz *matrix = (Matriz *)malloc(sizeof(Matriz));

	// Buffer to read lines from the file

	sscanf(firstLine, "%d %d %d %d %d", &matrix->rows, &matrix->colu, &matrix->variante, &matrix->cordX, &matrix->cordY);
	matrix->head = NULL;
	matrix->t_mancha = 0;
	matrix->pont = 0;
	matrix->location = 0;
	int indicolu = 1;
	char buffer[5000];

	for (int i = 0; i < matrix->colu; i++)
	{

		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL)
		{

			exit(0);
		}

		// Allocate memory for the columns of the new row
		newNode->data = (int *)malloc(sizeof(int) * matrix->rows);
		if (!newNode->data)
		{
			exit(0);
		}
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->indice = indicolu;
		indicolu++;
		// int i = 0;
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

	int indice = 0;
	int elementos = matrix->rows * matrix->colu;
	Node *coluna = matrix->head;
	int lidos = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL && lidos != elementos)
	{

		char *token = strtok(buffer, " ");
		while (token != NULL)
		{
			if (strcmp(token, "\n") == 0)
			{
				token = NULL;
				continue;
			}

			lidos++;
			escreveMatriz(matrix, &coluna, &indice, atoi(token));
			token = strtok(NULL, " ");
		}
	}
	return matrix;
}
void escreveMatriz(Matriz *matrix, Node **coluna, int *indice, int cor)
{
	(*coluna)->data[*indice] = cor;
	*coluna = (*coluna)->next;
	if (*coluna == NULL)
	{
		*coluna = matrix->head;
		(*indice)++;
	}

	return;
}
