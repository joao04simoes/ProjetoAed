#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

struct pilha_node *top = NULL;
// vai criando os elementos da pilha de forma a que o ultimo a entrar fique no topo, assim é mais facil de remover, passa a ser O(1)
void push(Node *ptr, int indice, int cor, Matriz *matrix)
{

    struct pilha_node *new_p = (struct pilha_node *)malloc(sizeof(struct pilha_node));

    if (new_p == NULL)
    {

        return; // Exit with an error code
    }

    new_p->ptr = ptr;
    new_p->indice = indice;
    new_p->cor = cor;
    new_p->matrix = matrix;
    new_p->link = NULL;
    new_p->link = top;
    top = new_p;
}

void pop()
{

    if (isEmpty())
    {
        return;
    }
    while (!isEmpty())
    {
        struct pilha_node *temp = top;
        top = top->link;

        // Call procurarMancha to process the node and its neighbors
        procurarMancha(temp->ptr, temp->indice, temp->cor, temp->matrix);

        // Free the temp node
        free(temp);
        temp = NULL;
    }
    return;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
