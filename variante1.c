#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

// função de encontrar as coordenadas e chama a função de procurar a mancha
Matriz *variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    int indice = 0;
    int cor = 0;
    int flag;

    if (1 <= matrix->cordX && matrix->cordX <= matrix->rows && 1 <= matrix->cordY && matrix->cordY <= matrix->colu) // verifica se as coordenadas estão fora
    {
        while (aux != NULL)
        {
            if (aux->indice == matrix->cordY) // break quando encontrar as coordenadas
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

    if (aux->data[indice] == -1) // se a cor da coordenada for -1 da return
        return matrix;

    if ((flag = procurarMancha(aux, indice, cor, matrix)) == 1) // verifica se existe mancha na coordenada
    {
        aux->data[indice] = -1;
        matrix->t_mancha++;
    }

    return matrix;
}

// verifica se existe mancha a volta da coordenada
int procurarMancha(Node *ptr, int indice, int cor, Matriz *matrix)
{
    int flag = 0;

    if (indice > 0 && cor == ptr->data[indice - 1]) // procura mancha no azulejo de cima
    {

        ptr->data[indice - 1] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr, indice - 1, cor, matrix); // coloca na pilha a coordenada
    }

    if (indice < matrix->rows - 1 && cor == ptr->data[indice + 1]) // procura mancha no azulejo baixo

    {

        ptr->data[indice + 1] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr, indice + 1, cor, matrix); // coloca na pilha a coordenada
    }

    if (ptr != matrix->head && cor == ptr->prev->data[indice]) // procura mancha no azulejo do lado esquerdo
    {

        ptr->prev->data[indice] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr->prev, indice, cor, matrix); // coloca na pilha a coordenada
    }

    if (ptr->next != NULL && cor == ptr->next->data[indice]) // procura mancha no azulejo do lado direito
    {

        ptr->next->data[indice] = -1;
        matrix->t_mancha++;
        flag = 1;
        push(ptr->next, indice, cor, matrix); // coloca na pilha a coordenada
    }

    return flag;
}
