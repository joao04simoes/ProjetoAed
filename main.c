/******************************************************************************
 * (c) 2023-2024
 * João Simões 106070
 * Tiago Gonçalves 106021
 *
 * Last modified: out 2023-10-06
 *
 * NAME
 *   main.c
 *
 * DESCRIPTION
 *   Main program for tileblaster AED project
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"
#include <time.h>

// função main do programa
int main(int argc, char *argv[])
{

	/*clock_t start, end;
	double execution_time;
	start = clock();*/
	Matriz *matrix;
	FILE *fp, *fs;
	int firstLine;
	if (argc != 2)
	{
		return 0;
	}

	const char *filename = argv[1]; // guarda o nome do ficheiro

	fp = fopen(filename, "r");
	if (fp == NULL)
	{

		exit(0);
	}

	fs = output(filename);
	while (fscanf(fp, "%d", &firstLine) == 1)
	{

		matrix = read_file(filename, fp, firstLine); // chamar a função de leitura do ficheiro

		if (matrix->variante == -1)
		{
			matrix = variante1(matrix);
		}
		if (matrix->variante >= 0) // realiza ambas as gravidades
		{
			matrix = dfs(matrix);
			if (matrix->done == true)
			{
				matrix = variante1(matrix);
			}
		}
		if (matrix->variante == -3)
		{
			matrix = dfsVar3(matrix);
		}

		escreverFicheiro(matrix, fs); // escreve no ficheiro o resultaod da matriz
		free_spotlist(matrix);
		freeMatriz(matrix); // função matriz
	}
	fclose(fp);
	fclose(fs);
	/*end = clock();
	execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", execution_time);*/

	return 0;
}
