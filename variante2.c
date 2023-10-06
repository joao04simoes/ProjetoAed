#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"
// realiza a gravidade vertical da matriz e retorna a matriz
Matriz *GravidadeVertical(Matriz *matrix) // começar a ler por baixo e escreve na lista apenas numeros validos quando chegar a cima vai para a proxima coluna
{
    Node *aux, *auxt;
    int j = 0;
    matrix = variante1(matrix); // procura mancha
    if (matrix->location == 1)
        while (!isEmpty())
            pop();
    aux = matrix->head;
    if (matrix->rows == 1) // apenas uma linha não é necessario fazer gravidade
        return matrix;
    while (aux != NULL) // realiza a gravidade vertical começando no final do vetor mantedo o valor se for cor se não for vai pra cima a procura de cor
    {
        for (int i = matrix->rows - 1; i > 0; i--)
        {
            if (aux->data[i] != -1)
                continue;
            j = i;
            while (aux->data[j] == -1 && j > 0)
            {
                if (j >= 0)
                    j--;
            }
            aux->data[i] = aux->data[j];
            aux->data[j] = -1;
        }
        auxt = aux->next;
        aux = auxt;
    }
    return matrix;
}
// realiza a gravidade horizontal da matriz e retorna a matriz
Matriz *GravidadeHorizontal(Matriz *matrix)
{
    Node *aux, *auxT, *coluna = matrix->head;
    int cor = 0;
    if (matrix->head->next == NULL) // apenas uma coluna não é necessario gravidade horizontal
        return matrix;
    while (coluna != NULL) // gravidade horizontal verifica se o vetor inteiro é -1 se for passa o no para o inicio da lista de colunas
    {
        cor = 0;
        for (int i = 0; i < matrix->rows; i++) // verifica se há cor
        {
            if (coluna->data[i] != -1)
            {
                cor = 1;
            }
        }
        if (cor == 0 && coluna->next == NULL && coluna != matrix->head) // caso de ser o ultimo no
        {
            aux = coluna;
            coluna = NULL;
            aux->prev->next = NULL;
            auxT = matrix->head;
            matrix->head = aux;
            aux->next = auxT;
            auxT->prev = aux;
            continue;
        }

        if (cor == 0 && coluna != matrix->head) // caso generico
        {
            aux = coluna;
            coluna = aux->next;
            aux->next->prev = aux->prev;
            aux->prev->next = aux->next;
            auxT = matrix->head;
            matrix->head = aux;
            aux->next = auxT;
            auxT->prev = aux;
            continue;
        }

        auxT = coluna->next;
        coluna = auxT;
    }
    return matrix;
}