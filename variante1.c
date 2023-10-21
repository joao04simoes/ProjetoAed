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
            if ((flag = procurarMancha(coluna, coluna, indice, coluna->data[indice], matrix)) == 1) // verifica se existe mancha na coordenada
            {

                coluna->data[indice] = -1;
                matrix = createSpotList(matrix, indice, nColuna);
                matrix = eliminateSpot(matrix);
                matrix = GravidadeVertical(matrix);
                matrix = GravidadeHorizontal(matrix);
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
int procurarMancha(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix)
{

    int flag = 0;
    printf("olaaa\n");
    if (indice > 0 && cor == ptrVer->data[indice - 1]) // procura mancha no azulejo de cima
    {

        ptr->data[indice - 1] = -1;
        ptrVer->data[indice - 1] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr, ptrVer, indice - 1, cor, matrix); // coloca na pilha a coordenada
    }
    printf("merdaaaaaaa\n");
    // printf("%d\n", ptrVer->data[1]);
    printf(" %d cior    %d\n", indice, cor);
    if (indice < matrix->rows - 1 && cor == ptrVer->data[indice + 1]) // procura mancha no azulejo baixo
    {
        printf("entrou\n");
        ptr->data[indice + 1] = -1;
        ptrVer->data[indice + 1] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr, ptrVer, indice + 1, cor, matrix); // coloca na pilha a coordenada
    }
    printf("fdssssssssss\n");

    printf("ola\n");
    if (ptrVer != matrix->head && cor == ptrVer->prev->data[indice]) // procura mancha no azulejo do lado esquerdo
    {
        printf("aquiiiii\n");
        ptr->prev->data[indice] = -1;
        ptrVer->prev->data[indice] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr->prev, ptrVer->prev, indice, cor, matrix); // coloca na pilha a coordenada
    }
    printf("shitttttttt\n");
    if (ptrVer->next != NULL && cor == ptrVer->next->data[indice]) // procura mancha no azulejo do lado direito
    {

        ptr->next->data[indice] = -1;
        ptrVer->next->data[indice] = -1;
        matrix->pontSpot++;
        flag = 1;
        push(ptr->next, ptrVer->next, indice, cor, matrix); // coloca na pilha a coordenada
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
        matrix->spotHead->next = NULL;
        matrix->spotTail->next = NULL;
        matrix->n_plays++;
        return matrix;
    }
    printf("generico\n");
    newSpot->next = matrix->spotHead;
    matrix->spotHead->prev = newSpot;
    matrix->spotHead = newSpot;
    matrix->spotHead->cordX = matrix->rows - cordX;
    matrix->spotHead->cordY = cordY;
    matrix->n_plays++;
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

    matrix->spotHead->value = matrix->pontSpot;
    matrix->pont = matrix->pont + (matrix->pontSpot * (matrix->pontSpot - 1));
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