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
    struct Node *next; // Ponteiro para a proxima linha
    struct Node *prev; // Ponteiro para a linha anterior
} Node;

typedef struct matriz
{
    Node *head; // Ponteiro para o inicio da listta
    int rows;   // Numero de linhas
    int colu;
    int cordX;
    int cordY;
    int variante;

} Matriz;

Matriz *read_file(const char *filename);
Matriz *variante1(Matriz *matrix);

#endif
