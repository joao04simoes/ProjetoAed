#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

struct pilha_node *topDfs = NULL;

// poe os elentos na pilha
void push_dfs(Matriz *matrix)
{

    struct pilha_node *new_p = (struct pilha_node *)malloc(sizeof(struct pilha_node));

    if (new_p == NULL)
    {

        return; // Exit
    }

    new_p->matrix = matrix;
    new_p->link = NULL;
    new_p->link = topDfs;
    topDfs = new_p;
}

// retira o elemento da pilha e faz chamada da função de procurar a mancha
Matriz *pop_dfs()
{
    Matriz *matrix;

    if (isEmpty_dfs()) // chama a funçao de verificar se a pilha esta vazia
    {
        exit(0);
    }
    if (!isEmpty_dfs())
    {

        struct pilha_node *temp = topDfs;
        topDfs = topDfs->link;
        matrix = temp->matrix;

        // liberta the temp node
        free(temp);
        temp = NULL;
    }
    return matrix;
}

// verifica se a pilha esta vazia se tiver retorna 1 se não estiver vazia retorna 0
int isEmpty_dfs()
{
    if (topDfs == NULL)
        return 1;
    else
        return 0;
}