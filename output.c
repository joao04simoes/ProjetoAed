#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

FILE *output(const char *filename){
  FILE *f;
  char *nome;
  

  char *last_dot = strrchr(filename, '.');
    
  if (last_dot == NULL) {
    fprintf(stderr, "ERROR: No file extension found.\n");
    exit(1);
  }
  
  size_t length_without_extension = last_dot - filename;

  // Allocate memory for the new file name with a different extension
  nome = (char *)malloc((length_without_extension + 13) * sizeof(char)); // Adjusted size to accommodate the new extension

  if (nome == NULL) {
    fprintf(stderr, "ERROR: Memory allocation failed.\n");
    exit(5);
  }

  sscanf(filename,"%[^.]",nome);
  strcat(nome, ".singleste");
  printf("%s\n", nome);
  
  f = fopen(nome, "w");
  return f;
  
}

void escreverFicheiro(Matriz *matrix, FILE *f){
  Node *aux=matrix->head, *auxT;
  fprintf(f, "%d %d %d %d %d\n", matrix->rows, matrix->colu, matrix->variante, matrix->cordX, matrix->cordY);
  if(matrix->variante == 2)
  {
    for (int i = 0; i < matrix->rows; i++)
	{
		aux = matrix->head;
		while (aux != NULL)
		{
			fprintf(f,"%d ", aux->data[i]); // a tabela esta a aprecer invertida primeira linha é a coluna
			auxT = aux->next;
			aux = auxT;
		}
		fprintf(f,"\n");
	}
    fprintf(f,"\n");
  }
  if(matrix->variante == 1){
    matrix->pont = matrix->t_mancha * (matrix->t_mancha -1);
    fprintf(f,"%d\n", matrix->pont);
    fprintf(f,"\n");
  }
  return;
}