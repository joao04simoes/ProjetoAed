#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfs(Matriz *matrix)

{
    Stack *stack = createStack((matrix->colu * matrix->rows), matrix);
    Node *coluna = matrix->tail, *colunaVer;
    spot *spot;
    Matriz *newMatrix = NULL, *matrixVer = NULL;
    int flag, indicolu = matrix->colu;

    int cor = 0;
    int bond = 0;
    int lastColor = 0;
    int lastSize = 0;

    newMatrix = iniciarMatrix(matrix, newMatrix);
    matrixVer = iniciarMatrix(matrix, matrixVer);

    colunaVer = matrixVer->tail;
    coluna = newMatrix->tail;
    lista_manchas *lista = init_listam();
    lista = fill_list(newMatrix, lista);
    lista->max = calcula_max(lista);

outerLoop:

    while (coluna != NULL)
    {

        for (int indice = newMatrix->rows - 1; indice > -1; indice--)
        {

            if (colunaVer->data[indice] != -1) // colocar colunaver talvez
            {
                cor = coluna->data[indice];
                coluna->data[indice] = -1;
                colunaVer->data[indice] = -1;
                newMatrix->pontSpot++;

                if ((flag = procurarMancha(coluna, colunaVer, indice, cor, newMatrix)) == 1)
                {

                    bond = thereishope_2(newMatrix, lista, cor);
                    if (bond == 1)
                    {
                        push_dfs(stack, matrix);
                        lastColor = cor;
                        lastSize = newMatrix->pontSpot;

                        lastSize = newMatrix->pontSpot;
                        lastColor = cor;

                        newMatrix = createSpotList(newMatrix, indice, indicolu);
                        newMatrix = eliminateSpot(newMatrix);

                        push_dfs(stack, matrixVer);
                        newMatrix = GravidadeVertical(newMatrix);
                        newMatrix = GravidadeHorizontal(newMatrix);

                        newMatrix->lastSize = lastSize;
                        newMatrix->lastColor = lastColor;
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
                                deleteStack(stack);
                                free_lista_manchas(lista);
                                return newMatrix;
                            }
                            deleteStack(stack);
                            free_lista_manchas(lista);
                            return newMatrix;
                        }
                        goto outerLoop;
                    }
                    else
                    {
                        newMatrix = copyMatrix(matrix, newMatrix);
                        newMatrix->pontSpot = 0;
                        coluna = newMatrix->tail;
                        colunaVer = matrixVer->tail;
                        indicolu = newMatrix->colu;
                        goto outerLoop;
                    }
                }
                else
                {

                    coluna->data[indice] = cor;
                    colunaVer->data[indice] = cor;
                    newMatrix->pontSpot--;
                }
            }

            if (indicolu == 1 && indice == 0)
            {

                if (stack->top == -1)
                {
                    freeMatriz(matrixVer);
                    freeMatriz(matrix);
                    newMatrix->done = false;
                    deleteStack(stack);
                    free_lista_manchas(lista);
                    return newMatrix;
                }

                add_tiles(newMatrix->lastSize, lista, newMatrix->lastColor);

                spot = newMatrix->spotHead;
                free(spot);

                matrixVer = pop_dfs(stack, matrixVer);
                newMatrix = pop_dfs(stack, newMatrix);

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
    free_lista_manchas(lista);
    return newMatrix;
}

Matriz *iniciarMatrix(Matriz *matrix, Matriz *newMatrix)
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
    newMatrix->maxPont = 0;
    newMatrix->done = false;
    newMatrix->head = NULL;
    newMatrix->tail = NULL;

    newMatrix = initMatrix(newMatrix);
    aux = matrix->head;
    newaux = newMatrix->head;

    while (aux != NULL)
    {
        memcpy(newaux->data, aux->data, matrix->rows * sizeof(int));
        aux = aux->next;
        newaux = newaux->next;
    }
    return newMatrix;
}

Matriz *copyMatrix(Matriz *matrix, Matriz *newMatrix)
{

    Node *aux, *newaux;
    newMatrix->colu = matrix->colu;
    newMatrix->rows = matrix->rows;
    newMatrix->rows = matrix->rows;
    newMatrix->colu = matrix->colu;
    newMatrix->pont = matrix->pont;
    newMatrix->lastColor = matrix->lastColor;
    newMatrix->lastSize = matrix->lastSize;
    newMatrix->maxPont = matrix->pont;
    newMatrix->spotHead = matrix->spotHead;
    newMatrix->spotTail = matrix->spotTail;
    newMatrix->n_plays = matrix->n_plays;
    newMatrix->variante = matrix->variante;
    newMatrix->pontSpot = 0;
    newMatrix->done = false;

    aux = matrix->head;
    newaux = newMatrix->head;

    while (aux != NULL)
    {
        memcpy(newaux->data, aux->data, matrix->rows * sizeof(int));
        aux = aux->next;
        newaux = newaux->next;
    }
    return newMatrix;
}
