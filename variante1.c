#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

// rever!!!
/*void procura_cima(Node *aux, Matriz *matrix)
{
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    int j = 1;
    while (i - j >= 0)
    {
        if (aux->data[i] == aux->data[i - j])
        {

            push(&(aux->data[i - j]));
            counter++;
            j++;
            new_p->ptr = ptr;
        }
        else
        {
            break; // Stop if not the same color
        }
    }
}

// rever!!!
void procura_baixo(Node *aux, Matriz *matrix)
{
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    int j = 1;
    while ((i + j) < matrix->rows)
    {
        if (aux->data[i] == aux->data[i + j])
        {

            push(&(aux->data[i + j]));
            counter++;
            j++;
        }
        else
        {
            break; // Stop if not the same color
        }
    }
}

// rever!!!
void procura_direita(Node *aux, Matriz *matrix)
{
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    Node *ptr;
    while (aux->next != NULL)
    {
        if (aux->data[i] == aux->next->data[i])
        {

            push(&(aux->next->data[i]));
            counter++;
            procura_cima(aux->next, matrix);
            procura_baixo(aux->next, matrix);
        }
        else
        {
            break; // Stop if not the same color
        }
        ptr = aux->next;
        aux = ptr;
    }
}

// olaaaaaaaaaaaaaaaaaaaaaaaaaaa
// rever!!!
void procura_esquerda(Node *aux, Matriz *matrix)
{
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    Node *ptr;
    while (aux->prev != NULL)
    {
        if (aux->data[i] == aux->prev->data[i])
        {

            push(&(aux->prev->data[i]));
            counter++;
            procura_cima(aux->prev, matrix);
            procura_baixo(aux->prev, matrix);
        }
        else
        {
            break; // Stop if not the same color
        }
        ptr = aux->prev;
        aux = ptr;
    }
}
*/
Matriz *variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    int indice = 0;
    int cor = 0;

    while (aux != NULL)
    {
        printf("loop procura\n");
        if (aux->indice == matrix->cordY)
        {
            printf("indice %d e cord %d \n ", aux->indice, matrix->cordY);
            break;
        }
        auxT = aux->next;
        aux = auxT;
    }

    indice = matrix->rows - matrix->cordX;
    printf("indice %d\n", indice);
    cor = aux->data[indice];
    printf("a cor eeeeeeeeeeeeeeeee %d\n", aux->data[indice]);
    aux->data[indice] = -1;
    printf("antes de procurar\n");
    matrix = procurarMancha(aux, indice, cor, matrix);

    return matrix; // como a variante 1 so pede o valor da mancha, para ja isto pode ficar assim, damos apenas return do valor da mancha
}
Matriz *procurarMancha(Node *ptr, int indice, int cor, Matriz *matrix)
{
    printf("procura\n");
    // procurar para cima
    if (indice > 0)
    {
        if (cor == ptr->data[indice - 1])
        {
            printf("cimaaaaaaa\n");
            ptr->data[indice - 1] = -1;
            push(ptr, indice, cor, matrix);
        }
    }

    // procurar para baixo
    if (indice < matrix->cordX)
    {
        if (cor == ptr->data[indice + 1])
        {
            printf("baixoooooo\n");
            ptr->data[indice + 1] = -1;
            push(ptr, indice, cor, matrix);
        }
    }

    // procurar para a esquerda
    if (ptr != matrix->head)
    {
        if (cor == ptr->prev->data[indice])
        {
            printf("esquerdaaaaaaa\n");
            ptr->prev->data[indice] = -1;
            push(ptr, indice, cor, matrix);
        }
    }

    // procurar para a direita
    if (ptr->next != NULL)
    {
        if (cor == ptr->next->data[indice])
        {
            printf("direita\n");
            ptr->next->data[indice] = -1;
            push(ptr, indice, cor, matrix);
        }
    }
    pop();
    return matrix;
}
