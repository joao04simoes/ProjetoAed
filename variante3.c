#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

Matriz *dfsVar3(Matriz *matrix)

{
    Stack *stack = createStack((matrix->colu * matrix->rows), matrix);
    Node *coluna = matrix->tail, *colunaVer;
    spot *spot, *maxSpot = NULL;
    Matriz *newMatrix = NULL, *matrixVer = NULL;
    int flag, indicolu = matrix->colu;

    int cor = 0;
    int playMax = 0;
    int antPlaymax = 0;
    int maxPont = 0;
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
                    // printf("coluna %d  e indice %d e cor %d\n", indicolu, indice, cor);

                    bond = thereishope_3(newMatrix, lista, cor, maxPont);
                    if (bond == 1)
                    {
                        push_dfs(stack, matrix);
                        lastColor = cor;
                        lastSize = newMatrix->pontSpot;

                        // printf("%d\n", newMatrix->pontSpot);
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
                if (newMatrix->pont > maxPont)
                {
                    // printf("maxpont\n");
                    maxPont = newMatrix->pont;
                    antPlaymax = playMax;
                    playMax = newMatrix->n_plays;
                    maxSpot = maxSpotList(maxSpot, matrix, antPlaymax, playMax);
                }

                if (stack->top == -1)
                {

                    freeMatriz(matrixVer);
                    freeMatriz(matrix);
                    newMatrix->done = false;
                    deleteStack(stack);
                    newMatrix->maxPont = maxPont;
                    newMatrix->maxSpot = maxSpot;
                    newMatrix->maxPlays = playMax;
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
    free_lista_manchas(lista);
    deleteStack(stack);
    return newMatrix;
}

spot *maxSpotList(spot *maxspot, Matriz *matrix, int n_antigas, int n_novas)
{
    spot *aux = maxspot, *auxT = matrix->spotHead, *guarda;

    for (int i = 0; i < n_antigas; i++)
    {
        // printf("freeee\n");
        guarda = aux->prev;
        free(aux);
        aux = guarda;
    }
    for (int i = 0; i < n_novas; i++)
    {

        spot *newSpot = (spot *)malloc(sizeof(spot));
        // printf("malloc\n");
        if (maxspot == NULL)
        {
            // printf("primeiro\n");
            maxspot = newSpot;
            maxspot->prev = NULL;
            maxspot->next = NULL;
            maxspot->cordX = auxT->cordX;
            maxspot->cordY = auxT->cordY;
        }
        else
        {
            // printf("generico\n");
            guarda = maxspot;
            maxspot = newSpot;
            maxspot->prev = guarda;
            maxspot->next = NULL;
            maxspot->cordX = auxT->cordX;
            maxspot->cordY = auxT->cordY;
        }
        auxT = auxT->next;
    }
    return maxspot;
}
