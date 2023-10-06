#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

// faz as verificações do ficheiro de entrada e cria o ficheiro de saida e retorna o ficheiro de saida
FILE *output(const char *filename)
{
  FILE *f;
  char *nome;

  char *last_dot = strrchr(filename, '.');

  if (last_dot == NULL)
  {
    exit(0);
  }

  size_t length_without_extension = last_dot - filename; // tamanho do nome sem extensao

  if (strcmp(last_dot, ".tilewalls1") != 0) // verifica a extençao de ficheiro de entrada
  {
    exit(0);
  }
  // aloca memoria para o nome do ficheiro de saida
  nome = (char *)malloc((length_without_extension + 12) * sizeof(char));

  if (nome == NULL)
  {
    exit(0);
  }

  strncpy(nome, filename, length_without_extension);
  nome[length_without_extension] = '\0';
  strcat(nome, ".singlestep"); // faz a junção do nome com a extensão

  f = fopen(nome, "w");
  free(nome);
  return f;
}

// escreve no ficheiro de saida os resultados das matrizes
void escreverFicheiro(Matriz *matrix, FILE *f)
{
  Node *aux = matrix->head, *auxT;
  fprintf(f, "%d %d %d %d %d\n", matrix->rows, matrix->colu, matrix->variante, matrix->cordX, matrix->cordY); // da print do cabeçalho
  if (matrix->variante == 2 && matrix->location == 1)                                                         // se for variante 2 percorre a matriz toda e escreve no ficheiro a matriz
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
  if (matrix->variante == 1 && matrix->location == 1) // se for variante1 escreve no ficheiro o resultado da mancha
  {
    matrix->pont = matrix->t_mancha * (matrix->t_mancha - 1);
    fprintf(f, "%d\n", matrix->pont);
    fprintf(f, "\n");
    return;
  }
  fprintf(f, "\n");
  return;
}