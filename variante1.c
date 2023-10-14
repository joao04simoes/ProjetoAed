#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

// função de encontrar as coordenadas e chama a função de procurar a mancha
Matriz *variante1(Matriz *matrix)
{
    Node *coluna = matrix->tail;
    int indice = matrix->rows - 1;
    int nColuna = matrix->colu;
    int flag = 0;
    matrix->pontSpot = 0;

    while (coluna != NULL && indice >= 0)
    {
        flag = 0;

        if (coluna->data[indice] != -1)
        {
            if ((flag = procurarMancha(coluna, indice, coluna->data[indice], matrix)) == 1) // verifica se existe mancha na coordenada
            {

                coluna->data[indice] = -1;
                matrix = createSpotList(matrix, indice, nColuna);
                matrix = eliminateSpot(matrix);
                printf(" %d %d\n", matrix->spotHead->cordX, matrix->spotHead->cordY);
                printf("%d\n", matrix->spotHead->value);
                printf("%d\n", matrix->spotHead->value = matrix->spotHead->value * (matrix->spotHead->value - 1));
                print(matrix);
                coluna = matrix->tail;
                nColuna = matrix->colu;
                indice = matrix->rows - 1;
                continue;
            }
        }
        if (indice > 0)
        {
            indice--;
        }
        else
        {
            if (coluna->prev == NULL)
                return matrix;
            else
            {

                coluna = coluna->prev;
                nColuna--;
                indice = matrix->rows - 1;
            }
        }
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
        matrix->pontSpot++;
        flag = 1;
        push(ptr, indice - 1, cor, matrix); // coloca na pilha a coordenada
    }

    if (indice < matrix->rows - 1 && cor == ptr->data[indice + 1]) // procura mancha no azulejo baixo

    {

        ptr->data[indice + 1] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr, indice + 1, cor, matrix); // coloca na pilha a coordenada
    }

    if (ptr != matrix->head && cor == ptr->prev->data[indice]) // procura mancha no azulejo do lado esquerdo
    {

        ptr->prev->data[indice] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr->prev, indice, cor, matrix); // coloca na pilha a coordenada
    }

    if (ptr->next != NULL && cor == ptr->next->data[indice]) // procura mancha no azulejo do lado direito
    {

        ptr->next->data[indice] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr->next, indice, cor, matrix); // coloca na pilha a coordenada
    }

    return flag;
}

// criar função que cria um novo na lista de manchas e coloca como head
Matriz *createSpotList(Matriz *matrix, int cordX, int cordY)
{
    spot *newSpot = (spot *)malloc(sizeof(spot));
    printf("malloc\n");
    if (matrix->spotTail == NULL)
    {
        printf("primeiro\n");
        matrix->spotTail = newSpot;
        matrix->spotHead = newSpot;
        matrix->spotTail->prev = NULL;
        matrix->spotHead->cordX = matrix->rows - cordX;
        matrix->spotHead->cordY = cordY;
        matrix->pontSpot++;
        return matrix;
    }
    printf("generico\n");
    matrix->spotHead->prev = newSpot;
    matrix->spotHead = newSpot;
    matrix->spotHead->cordX = matrix->rows - cordX;
    matrix->spotHead->cordY = cordY;
    matrix->pontSpot++;
    return matrix;
}

Matriz *eliminateSpot(Matriz *matrix)
{
    printf("eliminate\n");
    while (!isEmpty())
    { // da pop da lista enquanto houver elementos para procurar
        printf("pop\n");
        pop();
    }
    matrix = GravidadeVertical(matrix);
    matrix = GravidadeHorizontal(matrix);
    matrix->spotHead->value = matrix->pontSpot;
    matrix->pontSpot = 0;
    return matrix;
}

void print(Matriz *matrix)
{
    Node *aux, *auxT;

    for (int i = 0; i < matrix->rows; i++)
    {
        aux = matrix->head;
        while (aux != NULL)
        {
            printf("%d ", aux->data[i]);
            auxT = aux->next;
            aux = auxT;
        }
        printf("\n");
    }
}