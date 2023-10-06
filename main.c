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

// função main do programa
int main(int argc, char *argv[])
{
	Matriz *matrix;
	FILE *fp, *fs;
	char firstLine[100];
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
	while (fgets(firstLine, sizeof(firstLine), fp) != NULL)
	{

		matrix = read_file(filename, fp, firstLine); // chamar a função de leitura do ficheiro

		if (matrix->variante == 1)
		{
			matrix = variante1(matrix);
			while (!isEmpty()) // da pop da lista enquanto houver elementos para procurar
				pop();
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

	return 0;
}
