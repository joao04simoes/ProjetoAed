#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

// funçao free da matriz
void freeMatriz(Matriz *matrix)
{
    printf("antes de iniciar\n");
    Node *aux = matrix->head;

    while (aux != NULL)
    {
        printf("free\n");
        free(matrix->head->data); // free do vetor de dados
        aux = matrix->head->next;
        free(matrix->head); // free do no da lista
        matrix->head = aux;
    }
    free(matrix); // free da matriz ola
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