#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    int indice = 0;
    int cor = 0;
    int flag;

    if (1 <= matrix->cordX && matrix->cordX <= matrix->rows && 1 <= matrix->cordY && matrix->cordY <= matrix->colu)
    {
        while (aux != NULL)
        {

            if (aux->indice == matrix->cordY)
            {

                break;
            }
            auxT = aux->next;
            aux = auxT;
        }
        matrix->location = 1;
    }
    else
    {
        matrix->location = 0;
        return matrix;
    }

    indice = matrix->rows - matrix->cordX;

    cor = aux->data[indice];

    if (aux->data[indice] == -1)
        return matrix;

    if ((flag = procurarMancha(aux, indice, cor, matrix)) == 1)
    {
        aux->data[indice] = -1;
        matrix->t_mancha++;
    }

    return matrix;
}

int procurarMancha(Node *ptr, int indice, int cor, Matriz *matrix)
{
    int flag = 0;

    if (indice > 0 && cor == ptr->data[indice - 1])
    {

        ptr->data[indice - 1] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr, indice - 1, cor, matrix);
    }

    if (indice < matrix->rows - 1 && cor == ptr->data[indice + 1])
    {

        ptr->data[indice + 1] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr, indice + 1, cor, matrix);
    }

    if (ptr != matrix->head && cor == ptr->prev->data[indice])
    {

        ptr->prev->data[indice] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr->prev, indice, cor, matrix);
    }

    if (ptr->next != NULL && cor == ptr->next->data[indice])
    {

        ptr->next->data[indice] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr->next, indice, cor, matrix);
    }

    return flag;
}
