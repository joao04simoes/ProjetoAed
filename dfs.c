#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfs(Matriz *matrix)

{
    Node *coluna = matrix->tail, *colunaVer;
    Matriz *newMatrix, *matrixVer;
    spot *spot, *aux;
    int flag, indicolu = matrix->colu;
    int one = 1;
    int cor = 0;
    int mudar = 1;
    matrixVer = copyMatrix(matrix);
    colunaVer = matrixVer->tail;
    newMatrix = copyMatrix(matrix);
    coluna = newMatrix->tail;
outerLoop:
    while (coluna != NULL)
    {
        // printf("coluna %d\n", indicolu);
        for (int indice = newMatrix->rows - 1; indice > -1; indice--)
        {

            if (coluna->data[indice] != -1) // colocar colunaver talvez
            {

                if ((flag = procurarMancha(coluna, colunaVer, indice, coluna->data[indice], newMatrix)) == 1)
                {
                    // printf("coluna %d  e indice %d e cor %d\n", indicolu, indice, cor);

                    push_dfs(matrix);
                    coluna->data[indice] = -1;
                    colunaVer->data[indice] = -1;
                    newMatrix->pontSpot++;
                    newMatrix = createSpotList(newMatrix, indice, indicolu);
                    newMatrix = eliminateSpot(newMatrix);
                    push_dfs(matrixVer);
                    newMatrix = GravidadeVertical(newMatrix);
                    newMatrix = GravidadeHorizontal(newMatrix);
                    matrixVer = copyMatrix(newMatrix);
                    matrix = copyMatrix(newMatrix);
                    coluna = newMatrix->tail;
                    colunaVer = matrixVer->tail;
                    indicolu = newMatrix->colu;

                    if (newMatrix->pont >= newMatrix->variante)
                    {

                        newMatrix->done = true;
                        freeMatriz(matrixVer);
                        freeMatriz(matrix);
                        while (!isEmpty_dfs())
                        {
                            matrixVer = pop_dfs();

                            freeMatriz(matrixVer);
                        }
                        return newMatrix;
                    }
                    goto outerLoop;
                }
            }

            if (indicolu == 1 && indice == 0)
            {
                if (isEmpty_dfs())
                {
                    print(newMatrix);
                    printf("nada\n");
                    print(matrixVer);
                    freeMatriz(matrixVer);
                    freeMatriz(matrix);
                    return newMatrix;
                }

                spot = newMatrix->spotHead;
                free(spot);
                freeMatriz(matrixVer);
                freeMatriz(matrix);
                // printf("free spot\n");
                freeMatriz(newMatrix);

                // ver se a pilha esta vazia

                matrixVer = pop_dfs();
                newMatrix = pop_dfs();
                matrix = copyMatrix(newMatrix);
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
    return newMatrix;
}

Matriz *copyMatrix(Matriz *matrix)
{

    Node *aux, *newaux;
    Matriz *newMatrix = (Matriz *)malloc(sizeof(Matriz));

    newMatrix->rows = matrix->rows;
    newMatrix->colu = matrix->colu;
    newMatrix->pont = matrix->pont;
    newMatrix->spotHead = matrix->spotHead;
    newMatrix->spotTail = matrix->spotTail;
    newMatrix->n_plays = matrix->n_plays;
    newMatrix->head = NULL;
    newMatrix->tail = NULL;
    newMatrix->variante = matrix->variante;
    newMatrix->pontSpot = 0;
    newMatrix->done = false;

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