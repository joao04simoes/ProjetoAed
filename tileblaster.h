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
    int t_mancha; // nº de blocos da mancha
    int pont;
    int location;
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

Matriz *read_file(const char *filename, FILE *fp, char *firstLine);
void procura_cima(Node *aux, Matriz *matrix);
void procura_baixo(Node *aux, Matriz *matrix);
void procura_direita(Node *aux, Matriz *matrix);
void procura_esquerda(Node *aux, Matriz *matrix);
Matriz *variante1(Matriz *matrix);
int procurarMancha(Node *ptr, int indice, int cor, Matriz *matrix);
Matriz *GravidadeHorizontal(Matriz *matrix);
Matriz *GravidadeVertical(Matriz *matrix);
void push(Node *ptr, int indice, int cor, Matriz *matrix);
void pop();
int isEmpty();
FILE *output(const char *filename);
void escreverFicheiro(Matriz *matrix, FILE *f);
void freeMatriz(Matriz *matrix);
void escreveMatriz(Matriz *matrix, Node **coluna, int *indice, int cor);

#endif
