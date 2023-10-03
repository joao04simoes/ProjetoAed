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
    Node *head;   // Ponteiro para o inicio da listta
    int rows;     // Numero de linhas
    int colu;     // Numero de colunas
    int cordX;    // cordenada x do ponto que nos é dado
    int cordY;    // coordenada y do ponto que nos é dado
    int variante; // variante que nos é pedida

} Matriz;

extern struct pilha_node *top;

struct pilha_node
{
    struct Node *ptr;
    int indice;
    int cor;
    Matriz *matrix;
    struct pilha_node *link;
};

Matriz *read_file(const char *filename);
void procura_cima(Node *aux, Matriz *matrix);
void procura_baixo(Node *aux, Matriz *matrix);
void procura_direita(Node *aux, Matriz *matrix);
void procura_esquerda(Node *aux, Matriz *matrix);
Matriz *variante1(Matriz *matrix);
Matriz *procurarMancha(Node *ptr, int indice, int cor, Matriz *matrix);
void push(Node *ptr, int indice, int cor, Matriz *matrix);
void pop();
int isEmpty();

#endif
