#include <stdio.h>
#include "monty.h"
stack_t *stack = NULL;
int main(int argc, const char *argv[])
{
        int state;
        char *buffer = NULL;
        argc = argc;
        if (argv[1] == NULL)
                return (0);
        buffer = malloc(1024);
        if (buffer == NULL)
                return (0);
        state = open(argv[1], O_RDONLY, 0600);
        if (state == -1)
        {
                return (0);                                                                                                        
        }
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
        commandsCut = malloc(countCommands(buffer) * sizeof(char *));
        if (commandsCut == NULL)
        {
                free(buffer);
                printf("Error: malloc failed");
                exit(EXIT_FAILURE);
        }
        firstCommand = strtok(buffer, "\n");
        while (firstCommand != NULL)
        {
                commandsCut[i] = malloc((strlen(firstCommand) + 1) * sizeof(char));
                if (commandsCut[i] == NULL)
                {
                        free(buffer);
                        printf("Error: malloc failed");
                        exit(EXIT_FAILURE);
                }
                strcpy(commandsCut[i], firstCommand);
                firstCommand = strtok(NULL, "\n");
                i++;
        }
        free(firstCommand);
        executeCommand(commandsCut);
}


void executeCommand(char **Tokens)
{
        int i = 0, j = 0;
        instruction_t tipos[] ={
                {"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop}, {NULL, NULL}
        };

        char *tmp;
        tmp = strtok(Tokens[0], " ");
        while (Tokens[j] != NULL)
        {
                i = 0;
                while (tipos[i].opcode != NULL)
                {
                        if (strcmp(tmp, tipos[i].opcode) == 0)
                        {
                                tmp = strtok(NULL, " ");
                                if (tmp == NULL)
                                        tmp = "";
                                tipos[i].f(&stack, _atoi(tmp));
                                break;
                        }
                        i++;
                }
                j++;
                tmp = strtok(Tokens[j], " ");
        }
        free(tmp);
        i = 0;
        while (Tokens[i] != NULL)
                i++;
        free_grid(Tokens, i);
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
