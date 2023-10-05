#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

void freeMatriz(Matriz *matrix)
{
    Node *aux = matrix->head;
    while (matrix->head != NULL)
    {
        free(matrix->head->data);
        aux = matrix->head->next;
        free(matrix->head);
        matrix->head = aux;
    }
    free(matrix);
    return;
}