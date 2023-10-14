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

	clock_t start, end;
	double execution_time;
	start = clock();
	Matriz *matrix;
	FILE *fp, *fs;
	char firstLine[100];
	if (argc != 2)
	{
		return 0;
	}

	const char *filename = argv[1]; // guarda o nome do ficheiro
	printf("%s\n", filename);
	fp = fopen(filename, "r");
	if (fp == NULL)
	{

		exit(0);
	}

	fs = output(filename);
	while (fgets(firstLine, sizeof(firstLine), fp) != NULL)
	{

		matrix = read_file(filename, fp, firstLine); // chamar a função de leitura do ficheiro

		if (matrix->variante == 1)
		{
			matrix = variante1(matrix);
		}
		if (matrix->variante == 2) // realiza ambas as gravidades
		{
			matrix = GravidadeVertical(matrix);
			matrix = GravidadeHorizontal(matrix);
		}

		escreverFicheiro(matrix, fs); // escreve no ficheiro o resultaod da matriz

		freeMatriz(matrix); // função matriz
	}
	fclose(fp);
	fclose(fs);
	end = clock();
	execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", execution_time);

	return 0;
}
