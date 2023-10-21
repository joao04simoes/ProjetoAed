#ifndef TILEBLASTER_H
#define TILEBLASTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node
{
    int *data;  // Ponteiro para a coluna
    int linhas; // Numero de colunas
    int indice;
    struct Node *next; // Ponteiro para a proxima coluna
    struct Node *prev; // Ponteiro para a coluna anterior
} Node;

typedef struct spot
{
    int cordX;
    int cordY;
    int value;
    struct spot *next;
    struct spot *prev;

} spot;

typedef struct matriz
{
    Node *head; // Ponteiro para o inicio da listta
    Node *tail;
    spot *spotHead;
    spot *spotTail;
    int rows;     // Numero de linhas
    int colu;     // Numero de colunas
    int variante; // variante que nos é pedida
    int pontSpot;
    int pont;    // pontuação da matriz
    int n_plays; // numero de jogadas
    bool done;
} Matriz;

extern struct pilha_node *top;
extern struct pilha_node *topDfs;

struct pilha_node // estrura de cada elemnto da pilha
{
    struct Node *ptr; // ponteiro para uma coluna
    struct Node *ptrVer;
    int indice;              // indice do vetor da coluna
    int cor;                 // cor a procurar
    Matriz *matrix;          // ponteiro para a matriz
    struct pilha_node *link; // ponteiro para o proximo elemnto da pilha
};

Matriz *read_file(const char *filename, FILE *fp, char *firstLine);

Matriz *variante1(Matriz *matrix);
int procurarMancha(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix);
Matriz *GravidadeHorizontal(Matriz *matrix);
Matriz *GravidadeVertical(Matriz *matrix);

void push(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix);
void pop();
int isEmpty();

FILE *output(const char *filename);
void escreverFicheiro(Matriz *matrix, FILE *f);

void freeMatriz(Matriz *matrix);
void free_spotlist(Matriz *matrix);

void escreveMatriz(Matriz *matrix, Node **coluna, int *indice, int cor);
Matriz *eliminateSpot(Matriz *matrix);
Matriz *createSpotList(Matriz *matrix, int cordX, int cordY);
void print(Matriz *matrix);

Matriz *initMatrix(Matriz *matrix);
Matriz *dfs(Matriz *matrix);
Matriz *copyMatrix(Matriz *matrix);

void push_dfs(Matriz *matrix);
Matriz *pop_dfs();
int isEmpty_dfs();

void print2(Matriz *matrix);

#endif
