#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfs(Matriz *matrix)

{
    Node *coluna = matrix->tail, *colunaVer;
    Matriz *newMatrix, *matrixVer;
    spot *spot;
    int flag, indicolu = matrix->colu;
    matrixVer = copyMatrix(matrix);
    colunaVer = matrixVer->tail;
    push_dfs(matrix);
    print(matrix);
    newMatrix = copyMatrix(matrix);
    coluna = newMatrix->tail;
    while (coluna != NULL)
    {

        for (int indice = newMatrix->rows - 1; indice > -1; indice--)
        {
            printf("%d    %d\n ", indicolu, indice);
            if (coluna->data[indice] != -1)
            {
                if ((flag = procurarMancha(coluna, colunaVer, indice, coluna->data[indice], newMatrix)) == 1)
                {
                    printf("tamos na colunnnnnnna %d\n", indicolu);
                    coluna->data[indice] = -1;
                    colunaVer->data[indice] = -1;
                    newMatrix = createSpotList(newMatrix, indice, indicolu);
                    newMatrix = eliminateSpot(newMatrix);
                    printf("ver %d \n", newMatrix->pont);
                    print(matrixVer);
                    printf("new \n");
                    push_dfs(matrixVer);
                    newMatrix = GravidadeVertical(newMatrix);
                    newMatrix = GravidadeHorizontal(newMatrix);
                    print(newMatrix);
                    push_dfs(newMatrix);
                    newMatrix = copyMatrix(newMatrix);
                    matrixVer = copyMatrix(newMatrix);
                    coluna = newMatrix->tail;
                    colunaVer = matrixVer->tail;
                    indicolu = newMatrix->colu;
                    if (newMatrix->pont > newMatrix->variante)
                    {
                        printf("pontuação\n");
                        newMatrix->done = true;
                        freeMatriz(matrixVer);
                        while (!isEmpty_dfs())
                        {
                            matrixVer = pop_dfs();
                            printf("erro\n");
                            freeMatriz(matrixVer);
                            printf("depois do free\n");
                        }
                        return newMatrix;
                    }
                    continue;
                }
            }

            if (indicolu == 1 && indice == 0)
            {
                printf("nada\n");
                if (isEmpty_dfs())
                {

                    return newMatrix;
                }
                free(newMatrix);
                free(matrixVer);
                // ver se a pilha esta vazia
                matrixVer = pop_dfs();
                matrixVer = pop_dfs();
                newMatrix = pop_dfs();
                printf("popdfs\n");
                spot = newMatrix->spotHead;
                newMatrix->spotHead = newMatrix->spotHead->next;
                matrix->n_plays--;
                free(spot);
                coluna = newMatrix->tail;
                colunaVer = matrixVer->tail;
                indicolu = newMatrix->colu;
                break;
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