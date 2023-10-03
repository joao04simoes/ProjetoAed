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
    int *address;
    struct pilha_node *link;
} *top = NULL;


Matriz *read_file(const char *filename);
void procura_cima(Node *aux, Matriz *matrix);
void procura_baixo(Node *aux, Matriz *matrix);
void procura_direita(Node *aux, Matriz *matrix);
void procura_esquerda(Node *aux, Matriz *matrix);
int variante1(Matriz *matrix);
void push(int *ptr);
Node *pop();
int isEmpty();
Node *peek();

#endif


