#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

// faz leitura do ficheiro de entrada
Matriz *read_file(const char *filename, FILE *fp, char *firstLine)
{

	Matriz *matrix = (Matriz *)malloc(sizeof(Matriz));

	char buffer[5000]; // Buffer to read lines from the file

	sscanf(firstLine, "%d %d %d", &matrix->rows, &matrix->colu, &matrix->variante); // guarda o cabeçalho na estrutura da matriz
	matrix->head = NULL;
	matrix->tail = NULL;
	matrix->pontSpot = 0;
	matrix->pont = 0;
	matrix->n_plays = 0;
	matrix->spotTail = NULL;
	matrix->spotHead = NULL;
	matrix->done = false;

	matrix = initMatrix(matrix);
	int indice = 0;
	int elementos = matrix->rows * matrix->colu;
	Node *coluna = matrix->head;
	int lidos = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL && lidos != elementos) // le uma linha e guarda os valores na matriz
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

Matriz *initMatrix(Matriz *matrix)
{
	for (int i = 0; i < matrix->colu; i++)
	{

		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL)
		{
			exit(0);
		}

		// aloca memoria para o vetor de inteiros
		newNode->data = (int *)malloc(sizeof(int) * matrix->rows);
		if (!newNode->data)
		{
			exit(0);
		}
		newNode->next = NULL;
		newNode->prev = NULL;
		// newNode->indice = indicolu;
		// indicolu++;

		// coloca o novo no nalista
		if (matrix->head == NULL)
		{
			matrix->head = newNode;
			matrix->tail = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
			continue;
		}
		Node *auxT = NULL;

		auxT = matrix->tail;
		matrix->tail = newNode;
		auxT->next = newNode;
		newNode->prev = auxT;

		// reverrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
	}
	return matrix;
}

// escreve na matriz a cor do azulejo
void escreveMatriz(Matriz *matrix, Node **coluna, int *indice, int cor)
{
	(*coluna)->data[*indice] = cor; // guarda a cor na matriz
	*coluna = (*coluna)->next;
	if (*coluna == NULL) // se tiver na ultima coluna volta ao inicio e incrementa o indice do vetor para a proxima linha
	{
		*coluna = matrix->head;
		(*indice)++;
	}

	return;
}
