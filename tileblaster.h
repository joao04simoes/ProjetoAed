#ifndef TILEBLASTER_H
#define TILEBLASTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int *data;  // Ponteiro para a coluna
    int linhas; // Numero de colunas
    int indice;
    struct Node *next; // Ponteiro para a proxima coluna
    struct Node *prev; // Ponteiro para a coluna anterior
} Node;

typedef struct matriz
{
    Node *head; // Ponteiro para o inicio da listta
    int rows;   // Numero de linhas
    int colu;   //Numero de colunas
    int cordX;  //cordenada x do ponto que nos é dado
    int cordY;  //coordenada y do ponto que nos é dado
    int variante;   //variante que nos é pedida

} Matriz;

struct pilha_node {
    Node *pointer_tp;
    struct pilha_node *link;
} *top = NULL;


Matriz *read_file(const char *filename);
int variante1(Matriz *matrix);
void push(Node *ptr);
Node *pop();
int isEmpty();
Node *peek();

#endif


