#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfs(Matriz *matrix)

{
    Node *coluna = matrix->tail, *colunaVer;
    Matriz *newMatrix = matrix, *matrixVer;
    spot *spot;
    int flag, indicolu = matrix->colu;
    matrixVer = copyMatrix(matrix);
    colunaVer = matrixVer->tail;
    while (coluna != NULL)
    {
        indicolu--;
        for (int indice = newMatrix->rows - 1; indice > -1; indice--)
        {
            if ((flag = procurarMancha(coluna, colunaVer, indice, coluna->data[indice], newMatrix)) == 1)
            {
                push_dfs(newMatrix);
                newMatrix = copyMatrix(newMatrix);
                coluna->data[indice] = -1;
                colunaVer->data[indice] = -1;
                newMatrix = createSpotList(newMatrix, indice, indicolu);
                newMatrix = eliminateSpot(matrix);
                push_dfs(matrixVer);
                newMatrix = GravidadeVertical(newMatrix);
                newMatrix = GravidadeHorizontal(newMatrix);

                matrixVer = copyMatrix(newMatrix);
                coluna = newMatrix->tail;
                colunaVer = matrixVer->tail;
                indicolu = newMatrix->colu;
                if (matrix->pont > matrix->variante)
                {
                    matrix->done = true;
                    return matrix;
                }
                break;
            }
            else
            {
                free(newMatrix);
                // ver se a pilha esta vazia
                matrixVer = pop_dfs();
                newMatrix = pop_dfs();
                spot = newMatrix->spotHead;
                newMatrix->spotHead = newMatrix->spotHead->next;
                free(spot);
                coluna = newMatrix->tail;
                colunaVer = matrixVer->tail;
                indicolu = newMatrix->colu;
                break;
            }
        }
        coluna = coluna->prev;
        colunaVer = colunaVer->prev;
    }
    return newMatrix;
}

Matriz *copyMatrix(Matriz *matrix)
{

    Node *aux, *newaux;
    Matriz *newMatrix = (Matriz *)malloc(sizeof(Matriz));
    newMatrix = initMatrix(newMatrix);
    newMatrix->rows = matrix->rows;
    newMatrix->colu = matrix->colu;
    newMatrix->pont = matrix->pont;
    newMatrix->spotHead = matrix->spotHead;
    newMatrix->spotTail = matrix->spotTail;

    aux = matrix->head;
    newaux = newMatrix->head;

    while (aux != NULL)
    {
        for (int i = 0; i < matrix->rows; i++)
        {
            newaux->data[i] = aux->data[i];
        }
        aux = aux->next;
        newaux = newaux->next;
    }
    return newMatrix;
}