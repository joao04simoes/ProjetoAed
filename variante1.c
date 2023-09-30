#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    int encotrado = 0;
    int i = 0;

    while (aux != NULL && encotrado == 0)
    {
        i = 0;
        printf("indice aux %d\n", aux->indice);
        while (i < matrix->colu && encotrado == 0)
        {
            printf(" %d == %d  e %d == %d\n", aux->indice, matrix->cordY, i + 1, matrix->cordX);
            printf("ciuclo i\n");
            if (aux->indice == matrix->cordY && i + 1 == matrix->cordX)
            {
                encotrado = 1;
                printf("encontrou\n");
                break;
            }
            i++;
        }
        if (encotrado == 1)
        {
            break;
        }

        auxT = aux->next;
        aux = auxT;
    }

    return matrix;
}