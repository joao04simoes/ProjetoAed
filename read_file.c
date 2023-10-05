#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *read_file(const char *filename, FILE *fp, char *firstLine)
{

	Matriz *matrix = (Matriz *)malloc(sizeof(Matriz));

	// Buffer to read lines from the file
	char buffer[5000];
	sscanf(firstLine, "%d %d %d %d %d", &matrix->rows, &matrix->colu, &matrix->variante, &matrix->cordX, &matrix->cordY);
	matrix->head = NULL;
	matrix->t_mancha = 0;
	matrix->pont = 0;
	matrix->location = 0;
	int indicolu = 1;
	if (matrix->variante != 1 && matrix->variante != 2)
	{

		while (fgets(buffer, sizeof(buffer), fp) != NULL)
		{
			if (strcmp(buffer, "\n") == 0)
				return matrix;
		}
	}

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

	int i = 0;
	int counter_linhas = 0;
	int j = 0;
	Node *aux = matrix->head, *auxT = NULL;
	while (fgets(buffer, sizeof(buffer), fp) != NULL && counter_linhas < matrix->rows)
	{

		char *token = strtok(buffer, " ");

		while (token != NULL && j < matrix->colu)
		{
			printf("1111111111 %s  e j %d  e matrix %d e  i %d\n", token, j, matrix->colu, i);
			aux->data[i] = atoi(token);
			auxT = aux->next;
			aux = auxT;
			j++;
			token = strtok(NULL, " ");
		}
		while (token != NULL)
		{
			j = 0;
			i++;
			aux = matrix->head;
			while (token != NULL && j < matrix->colu)
			{

				printf("222222222 %s  e j %d  e matrix %d e i %d\n", token, j, matrix->colu, i);
				aux->data[i] = atoi(token);
				auxT = aux->next;
				aux = auxT;
				j++;
				token = strtok(NULL, " ");
			}
			if (token == NULL)
				i++;
		}

		printf("saiu\n");
		if (j < matrix->colu)
		{
			auxT = aux->next;
			aux = auxT;
			continue;
		}

		i++;
		counter_linhas++;
		aux = matrix->head;
	}

	return matrix;
}
