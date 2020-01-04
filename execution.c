#include <stdio.h>
#include "monty.h"
stack_t *stack = NULL;
int main(int argc, const char *argv[])
{
        int state;
        char *buffer = NULL;
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file");
                exit(EXIT_FAILURE);
        }
        if (argv[1] == NULL)
                return (0);
        state = open(argv[1], O_RDONLY, 0600);
        if (state < 0)
        {
                fprintf(stderr, "Error: Can't open file %s", argv[1]);
                exit(EXIT_FAILURE);
        }
        buffer = malloc(1024);
        if (buffer == NULL)
                return (0);
        read(state, buffer, 1024);
        close(state);
        checkExecution(buffer);
        free(buffer);
        free_dlistint(stack);
        return (0);
}



void checkExecution(char *buffer)
{
        int i = 0;
        char **commandsCut;
        char *firstCommand;
        char deli[] = "\t\n";
        commandsCut = malloc(countCommands(buffer) * sizeof(char *));
        if (commandsCut == NULL)
        {
                free(buffer);
                fprintf(stderr, "Error: malloc failed");
                exit(EXIT_FAILURE);
        }
        firstCommand = strtok(buffer, deli);
        while (firstCommand != NULL)
        {
                commandsCut[i] = malloc((strlen(firstCommand)) * sizeof(char));
                if (commandsCut[i] == NULL)
                {
                        free(buffer);
                        fprintf(stderr, "Error: malloc failed");
                        exit(EXIT_FAILURE);
                }
                strcpy(commandsCut[i], firstCommand);
                firstCommand = strtok(NULL, deli);
                i++;
        }
        free(firstCommand);
        executeCommand(commandsCut);
}


void executeCommand(char **Tokens)
{

        int j = 0, len = 0;
        while (Tokens[len] != NULL)
                len++;
        while (j < len)
        {
                printf("Estoen el while\n");
                if (callFunction(Tokens[j], j) == 1)
                {
                        free_grid(Tokens, len);
                        fprintf(stderr, "L%d: unknown instruction %s", j, Tokens[j]);
                        exit(EXIT_FAILURE);
                }
                j++;
                printf("Aqui fallo--%i", len);
        }
        free_grid(Tokens, len);
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
