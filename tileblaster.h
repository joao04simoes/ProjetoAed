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
    spot *maxSpot;
    int lastColor;
    int lastSize;
    int rows;     // Numero de linhas
    int colu;     // Numero de colunas
    int variante; // variante que nos é pedida
    int pontSpot;
    int pont;    // pontuação da matriz
    int n_plays; // numero de jogadas
    int maxPont;
    int maxPlays;
    bool done;
} Matriz;

/* extern struct pilha_node *top;

struct pilha_node // estrura de cada elemnto da pilha
{
    struct Node *ptr; // ponteiro para uma coluna
    struct Node *ptrVer;
    int indice;              // indice do vetor da coluna
    int cor;                 // cor a procurar
    Matriz *matrix;          // ponteiro para a matriz
    struct pilha_node *link; // ponteiro para o proximo elemnto da pilha
};*/

Matriz *read_file(const char *filename, FILE *fp, int firstLine);

Matriz *variante1(Matriz *matrix);
int procurarMancha(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix);
int existeMancha(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix);
Matriz *GravidadeHorizontal(Matriz *matrix);
Matriz *GravidadeVertical(Matriz *matrix);

/*void push(Node *ptr, Node *ptrVer, int indice, int cor, Matriz *matrix);
void pop();
int isEmpty();*/

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
Matriz *dfsVar3(Matriz *matrix);
Matriz *copyMatrix(Matriz *matrix, Matriz *newMatrix);
Matriz *iniciarMatrix(Matriz *matrix, Matriz *newMatrix);

/*void push_dfs(Matriz *matrix);
Matriz *pop_dfs();
int isEmpty_dfs();*/

void print2(Matriz *matrix);

struct stack_
{
    int top;
    unsigned capacity;
    Matriz **array;
};

typedef struct stack_ Stack;

Stack *createStack(unsigned capacity, Matriz *matrix);
int isFull(Stack *);
int isEmpty_dfs(Stack *);
void push_dfs(Stack *, Matriz *matrix);
Matriz *pop_dfs(Stack *stack, Matriz *matrix);
Matriz *peek(Stack *);
void deleteStack(Stack *stack);

spot *maxSpotList(spot *maxspot, Matriz *matrix, int n_antigas, int n_novas);
void free_maxSpot(Matriz *matrix);

typedef struct No
{
    int cor;
    int count;
    struct No *next;
} No;

typedef struct lista_manchas
{
    int n_cores;
    int max;
    struct No *head;
} lista_manchas;

int thereishope_2(Matriz *newmatrix, lista_manchas *lista, int cor);
int thereishope_3(Matriz *newmatrix, lista_manchas *lista, int cor, int maxPont);
lista_manchas *init_listam();
lista_manchas *fill_list(Matriz *newmatrix, lista_manchas *lista);
No *novo_no(lista_manchas *lista);
int find_color_first(lista_manchas *lista, int cor);
int calcula_max(lista_manchas *lista);
void revert_play(lista_manchas *lista, Matriz *matrix, int cor);
void free_lista_manchas(lista_manchas *lista);
void add_tiles(int size, lista_manchas *lista, int cor);

#endif
