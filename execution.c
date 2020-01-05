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
	int j = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
		return (0);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(buffer_size * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &buffer_size, file))
	{
		if (callFunction(buffer, j) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s", j, buffer);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	fclose(file);
	free(buffer);
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
