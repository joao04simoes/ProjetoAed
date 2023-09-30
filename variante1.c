#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

Matriz *variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    //int encotrado = 0;
    //int i = 0;

    while (aux != NULL)
    {
        if(aux->indice == matrix->cordX)
            break;
    
        auxT = aux->next;
        aux = auxT;
    }

    //aux->data[matrix->cordY-1];
    


    return matrix;
}