#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

FILE *output(const char *filename)
{
  FILE *f;
  char *nome;

  char *last_dot = strrchr(filename, '.');

  if (last_dot == NULL)
  {
    exit(0);
  }

  size_t length_without_extension = last_dot - filename;

  if (strcmp(last_dot, ".tilewalls1") != 0)
  {
    exit(0);
  }
  // Allocate memory for the new file name with a different extension
  nome = (char *)malloc((length_without_extension + 12) * sizeof(char)); // Adjusted size to accommodate the new extension

  if (nome == NULL)
  {
    exit(0);
  }

  strncpy(nome, filename, length_without_extension);
  nome[length_without_extension] = '\0';
  strcat(nome, ".singlestep");

  f = fopen(nome, "w");
  free(nome);
  return f;
}

void escreverFicheiro(Matriz *matrix, FILE *f)
{
  Node *aux = matrix->head, *auxT;
  fprintf(f, "%d %d %d %d %d\n", matrix->rows, matrix->colu, matrix->variante, matrix->cordX, matrix->cordY);
  if (matrix->variante == 2 && matrix->location == 1)
  {
    for (int i = 0; i < matrix->rows; i++)
    {
      aux = matrix->head;
      while (aux != NULL)
      {
        fprintf(f, "%d ", aux->data[i]);
        auxT = aux->next;
        aux = auxT;
      }
      fprintf(f, "\n");
    }
    fprintf(f, "\n");
    return;
  }
  if (matrix->variante == 1 && matrix->location == 1)
  {
    matrix->pont = matrix->t_mancha * (matrix->t_mancha - 1);
    fprintf(f, "%d\n", matrix->pont);
    fprintf(f, "\n");
    return;
  }
  fprintf(f, "\n");
  return;
}