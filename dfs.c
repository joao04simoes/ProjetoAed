#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfs(Matriz *matrix)

{
    Stack *stack = createStack((matrix->colu * matrix->rows));
    Node *coluna = matrix->tail, *colunaVer;
    spot *spot, *aux;
    Matriz *newMatrix = NULL, *matrixVer = NULL;
    int flag, indicolu = matrix->colu;
    int one = 1;
    int cor = 0;
    int mudar = 1;

    newMatrix = copyMatrix(matrix, newMatrix);
    matrixVer = copyMatrix(matrix, matrixVer);

    colunaVer = matrixVer->tail;
    coluna = newMatrix->tail;
outerLoop:

    while (coluna != NULL)
    {

        for (int indice = newMatrix->rows - 1; indice > -1; indice--)
        {

            if (coluna->data[indice] != -1) // colocar colunaver talvez
            {

                if ((flag = procurarMancha(coluna, colunaVer, indice, coluna->data[indice], newMatrix)) == 1)
                {
                    // printf("coluna %d  e indice %d e cor %d\n", indicolu, indice, cor);

                    push_dfs(stack, (Item)matrix);
                    coluna->data[indice] = -1;
                    colunaVer->data[indice] = -1;
                    newMatrix->pontSpot++;
                    newMatrix = createSpotList(newMatrix, indice, indicolu);
                    newMatrix = eliminateSpot(newMatrix);

                    push_dfs(stack, (Item)matrixVer);
                    newMatrix = GravidadeVertical(newMatrix);
                    newMatrix = GravidadeHorizontal(newMatrix);
                    matrixVer = copyMatrix(newMatrix, matrixVer);
                    matrix = copyMatrix(newMatrix, matrix);
                    coluna = newMatrix->tail;
                    colunaVer = matrixVer->tail;
                    indicolu = newMatrix->colu;

                    if (newMatrix->pont >= newMatrix->variante)
                    {

                        newMatrix->done = true;
                        freeMatriz(matrixVer);
                        freeMatriz(matrix);
                        while (isEmpty_dfs(stack) == 0)
                        {

                            Matriz *aux;
                            aux = (Matriz *)pop_dfs(stack);

                            freeMatriz(aux);
                        }

                        deleteStack(stack);
                        return newMatrix;
                    }
                    goto outerLoop;
                }
            }

            if (indicolu == 1 && indice == 0)
            {

                if (isEmpty_dfs(stack) == 1)
                {
                    print(newMatrix);

                    print(matrixVer);
                    freeMatriz(matrixVer);
                    freeMatriz(matrix);
                    newMatrix->done = false;
                    deleteStack(stack);
                    return newMatrix;
                }

                spot = newMatrix->spotHead;
                free(spot);
                freeMatriz(newMatrix);
                freeMatriz(matrix);
                freeMatriz(matrixVer);
                // ver se a pilha esta vazia

                matrixVer = (Matriz *)pop_dfs(stack);
                newMatrix = (Matriz *)pop_dfs(stack);
                matrix = copyMatrix(newMatrix, matrix);
                coluna = newMatrix->tail;
                colunaVer = matrixVer->tail;
                indicolu = newMatrix->colu;
                goto outerLoop;
            }
        }
        coluna = coluna->prev;
        colunaVer = colunaVer->prev;
        indicolu--;
    }
    deleteStack(stack);
    return newMatrix;
}

Matriz *copyMatrix(Matriz *matrix, Matriz *newMatrix)
{

    Node *aux, *newaux;
    newMatrix = (Matriz *)malloc(sizeof(Matriz));
    newMatrix->colu = matrix->colu;
    newMatrix->rows = matrix->rows;
    newMatrix->rows = matrix->rows;
    newMatrix->colu = matrix->colu;
    newMatrix->pont = matrix->pont;
    newMatrix->spotHead = matrix->spotHead;
    newMatrix->spotTail = matrix->spotTail;
    newMatrix->n_plays = matrix->n_plays;
    newMatrix->variante = matrix->variante;
    newMatrix->pontSpot = 0;
    newMatrix->done = false;
    newMatrix->head = NULL;
    newMatrix->tail = NULL;

    newMatrix = initMatrix(newMatrix);
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
