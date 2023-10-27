#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

// funçao free da matriz
void freeMatriz(Matriz *matrix)
{

    Node *aux = matrix->head;

    while (aux != NULL)
    {

        free(matrix->head->data); // free do vetor de dados
        aux = matrix->head->next;
        free(matrix->head); // free do no da lista
        matrix->head = aux;
    }
    free(matrix);
    return;
}

void free_spotlist(Matriz *matrix)
{

    spot *aux = matrix->spotHead;
    while (matrix->spotHead != NULL)
    {
        aux = matrix->spotHead->next;
        free(matrix->spotHead);
        matrix->spotHead = aux;
    }
    return;
}
void free_maxSpot(Matriz *matrix)
{

    spot *aux = matrix->maxSpot;
    for (int i = 0; i < matrix->maxPlays; i++)
    {

        aux = matrix->maxSpot->prev;
        free(matrix->maxSpot);
        matrix->maxSpot = aux;
    }
    return;
}