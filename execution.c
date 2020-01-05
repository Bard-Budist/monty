#include <stdio.h>
#include "monty.h"
stack_t *stack = NULL;
/**
 * main - main functions
 * @argc: Conunt argumnets
 * @argv: Arguments
 * Return: 1
*/
int main(int argc, const char *argv[])
{
	FILE *file;
	char *buffer = NULL;
	size_t buffer_size = 80;
	int j = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
		return (0);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buffer_size, file) != -1)
	{
		if (buffer[0] == '#')
			continue;
		printErrors(callFunction(buffer, j), j, buffer, file);
		j++;
	}
	freeAll(buffer, file);
	return (0);
}

/**
 * free_grid - function that free the double pointer
 * @grid : double pointer for the Tokens
 * @height : height size of the grid
*/
void free_grid(char **grid, int height)
{
	int i = 0;

	for (i = 0; i < height; i++)
		if (grid[i] != NULL)
		{
			free(grid[i]);
		}
	free(grid);
}

/**
 * printErrors - Print Error
 * @error: Number of error
 * @line: Line number
 * @buffer: Buffer
 * @file: File
*/
void printErrors(int error, int line, char *buffer, FILE *file)
{
	switch (error)
	{
		case 1:
			fprintf(stderr, "L%i: unknown instruction %s\n", line, buffer);
			break;
		case 2:
			fprintf(stderr, "L%i: usage: push integer\n", line);
			break;
		case 3:
			fprintf(stderr, "L%i: can't pint, stack empty\n", line);
			break;
		case 4:
			fprintf(stderr, "L%i: can't pop an empty stack\n", line);
			break;
		case 5:
			fprintf(stderr, "L%i: can't swap, stack too short\n", line);
			break;
		case 6:
			fprintf(stderr, "L%i: can't add, stack too short\n", line);
			break;
		case 7:
			fprintf(stderr, "L%i: can't sub, stack too short\n", line);
			break;
		case 8:
			fprintf(stderr, "L%i: can't div, stack too short\n", line);
			break;
	}
	if (error > 8)
		morePrintErrors(error, line, buffer, file);

	if (error != 0)
	{
		freeAll(buffer, file);
		exit(EXIT_FAILURE);
	}
}
/**
 * freeAll - freee all
 * @buffer: free buffer
 * @file: File
*/
void freeAll(char *buffer, FILE *file)
{
	free(buffer);
	free_dlistint(&stack);
	fclose(file);
}
/**
 * morePrintErrors - Print Error
 * @error: Number of error
 * @line: Line number
 * @buffer: Buffer
 * @file: File
*/
void morePrintErrors(int error, int line, char *buffer, FILE *file)
{
	switch (error)
	{
		case 9:
			fprintf(stderr, "L%i: division by zero\n", line);
			break;
		case 10:
			fprintf(stderr, "L%i: can't mul, stack too short\n", line);
			break;
		case 11:
			fprintf(stderr, "L%i: can't mod, stack too short\n", line);
			break;
		case 12:
			fprintf(stderr, "L%i: division by zero\n", line);
			break;
	}
	if (error != 0)
	{
		freeAll(buffer, file);
		exit(EXIT_FAILURE);
	}
}
