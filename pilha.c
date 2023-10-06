#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

struct pilha_node *top = NULL;
// poe os elentos na pilha
void push(Node *ptr, int indice, int cor, Matriz *matrix)
{

    struct pilha_node *new_p = (struct pilha_node *)malloc(sizeof(struct pilha_node));

    if (new_p == NULL)
    {

        return; // Exit
    }

    new_p->ptr = ptr;
    new_p->indice = indice;
    new_p->cor = cor;
    new_p->matrix = matrix;
    new_p->link = NULL;
    new_p->link = top;
    top = new_p;
}

// retira o elemnto da oilha e faz chamada da função de procurar a mancha
void pop()
{

    if (isEmpty()) // chama a funçao de verificar se a pilha esta vazia
    {
        return;
    }
    while (!isEmpty())
    {
        struct pilha_node *temp = top;
        top = top->link;

        // chama a funçao procurarMancha to process the node and its neighbors
        procurarMancha(temp->ptr, temp->indice, temp->cor, temp->matrix);

        // liberta the temp node
        free(temp);
        temp = NULL;
    }
    return;
}

// verifica se a pilha esta vazia se tiver retorna 1 se não estiver vazia retorna 0
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
