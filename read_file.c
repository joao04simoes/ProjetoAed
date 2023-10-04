#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *read_file(const char *filename,FILE *fp, char *firstLine)
{
	
	Matriz *matrix = (Matriz *)malloc(sizeof(Matriz));

	char buffer[1024]; // Buffer to read lines from the file



		
		sscanf(firstLine, "%d %d %d %d %d", &matrix->rows, &matrix->colu, &matrix->variante, &matrix->cordX, &matrix->cordY);
		matrix->head = NULL;
		matrix->t_mancha = 0;
		matrix->pont = 0;
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
		int counter_linhas = 0;
		while (fgets(buffer, sizeof(buffer), fp) != NULL && counter_linhas < matrix->rows)
		{

			printf("loop linhas\n");
			char *token = strtok(buffer, " ");
			Node *aux = matrix->head, *auxT = NULL;

			for (int j = 0; j < matrix->colu; j++) //se estamos a por em cada posição do vetor os numeros das colunas nao deviamos ter l <= matrix->rows, acaba por ser o mesmo.
			{
				printf("novo dado %d\n", atoi(token));
				aux->data[i] = atoi(token);
				auxT = aux->next;
				aux = auxT;
				token = strtok(NULL, " ");
			}
			i++;
			counter_linhas++;

		}
		
	
	return matrix;
}
