#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *GravidadeVertical(Matriz *matrix) // começar a ler por baixo e escreve na lista apenas numeros validos quando chegar a cima vai para a proxima coluna
{
    Node *aux, *auxt;
    int j = 0;
    matrix = variante1(matrix);
    if (matrix->location == 1)
        while (!isEmpty())
            pop();
    aux = matrix->head;
    while (aux != NULL)
    {
        for (int i = matrix->rows - 1; i > 0; i--)
        {
            if (aux->data[i] != -1)
                continue;
            j = i;
            while (aux->data[j] == -1 && j > 0)
            {
                if (j >= 0)
                    j--;
            }
            aux->data[i] = aux->data[j];
            aux->data[j] = -1;
        }
        auxt = aux->next;
        aux = auxt;
    }
    return matrix;
}

Matriz *GravidadeHorizontal(Matriz *matrix)
{
    Node *aux, *auxT, *coluna = matrix->head;
    int cor = 0;
    while (coluna != NULL)
    {
        cor = 0;
        for (int i = 0; i < matrix->rows; i++)
        {
            if (coluna->data[i] != -1)
                cor = 1;
        }
        if (cor == 0 && coluna->next == NULL)
        {
            aux = coluna;
            coluna = NULL;
            aux->prev->next = NULL;
            auxT = matrix->head;
            matrix->head = aux;
            aux->next = auxT;
            auxT->prev = aux;
            continue;
        }

        if (cor == 0 && coluna != matrix->head)
        {
            aux = coluna;
            coluna = aux->next;
            aux->next->prev = aux->prev;
            aux->prev->next = aux->next;
            auxT = matrix->head;
            matrix->head = aux;
            aux->next = auxT;
            auxT->prev = aux;
            continue;
        }

        auxT = coluna;
        coluna = auxT->next;
    }
    return matrix;
}