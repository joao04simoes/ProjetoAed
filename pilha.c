#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"


//vai criando os elementos da pilha de forma a que o ultimo a entrar fique no topo, assim é mais facil de remover, passa a ser O(1)
void push (int *ptr) {
    
    struct pilha_node *new_p = (struct pilha_node *)malloc(sizeof(struct pilha_node));

    if (new_p == NULL) {
        fprintf(stderr, "Memory allocation failed for stack.\n");
        return;  // Exit with an error code
    }

    new_p->address = ptr;
    new_p->link = NULL;
    new_p->link = top;
    top = new_p;
}

Node *pop() {
    struct pilha_node* temp;
    temp = top;

    if(isEmpty()) {
       fprintf(stderr, "A pilha encontra-se vazia.\n");
       return NULL; 
    }

    Node *pt = temp->address;
    top = top->link;
    free(temp);
    temp = NULL;
    return pt;
}

int isEmpty() {
    if(top == NULL)
        return 1;
    else
        return 0;
}

//funça para ver o que está no topo da pilha
Node *peek() {
    if(isEmpty()) {
        fprintf(stderr, "A pilha encontra-se vazia.\n");
        return NULL; 
        }
    return top->address;
}

/*O que eu estava a pensar era fazer uma pilha que guarde os apontadores para os elementos da matriz, assim nao temos de estar a percorrer a matriz toda sempre que queremos remover
os elementos, basta ir à pilha e aceder ao top e depois dar pop e assim sucessivamente
AINDA NAO FOI TESTADO*/
