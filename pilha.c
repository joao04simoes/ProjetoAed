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
        fprintf(stderr, "Memory allocation failed for stack.\n");
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
    struct pilha_node *temp;
    temp = top;

    if (isEmpty())
    {
        fprintf(stderr, "A pilha encontra-se vazia.\n");
        return;
    }
    procurarMancha(temp->ptr, temp->indice, temp->cor, temp->matrix);
    top = top->link;
    free(temp);
    temp = NULL;
    return;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

/*O que eu estava a pensar era fazer uma pilha que guarde os apontadores para os elementos da matriz, assim nao temos de estar a percorrer a matriz toda sempre que queremos remover
os elementos, basta ir à pilha e aceder ao top e depois dar pop e assim sucessivamente
AINDA NAO FOI TESTADO*/
