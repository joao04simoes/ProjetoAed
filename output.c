#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

  if (strcmp(last_dot, ".tilewalls") != 0) // verifica a extençao de ficheiro de entrada
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
  spot *aux = matrix->spotTail;

  fprintf(f, "%d %d %d \n", matrix->rows, matrix->colu, matrix->variante); // da print do cabeçalho
  if (matrix->variante == -1)                                               // se for variante 2 percorre a matriz toda e escreve no ficheiro a matriz
  {
    fprintf(f, "%d %d \n", matrix->n_plays, matrix->pont);
    while(aux != NULL) {
      fprintf(f, "%d %d \n",aux->cordX, aux->cordY);
      aux = aux->prev;
    }
    fprintf(f, "\n");
    return;
  }

  fprintf(f, "\n");
  return;
}