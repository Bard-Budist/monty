#include  "monty.h"
int countTokens(char *string)
{
        int i = 0;
        char *tmp;

        tmp = strtok(string, " ");
        while (tmp != NULL)
        {
                i++;
                tmp = strtok(NULL, " ");
        }
        return (i);
}

int callFunction(char *tmp, int j)
{
        int i = 0;
        char *tem2;
        instruction_t tipos[] ={
                {"push", _push}, {"pall", _pall}, {"pint", _pint},
                {"pop", _pop}, {"add", _add}, {"nop", _nop}, {NULL, NULL}
        };
        j = j;
        tem2 = strtok(tmp, " ");
        while (tipos[i].opcode != NULL)
        {
                if (strcmp(tem2, tipos[i].opcode) == 0)
                {
                        /*
                        printf("%s\n", tem2);
                        if (strcmp(tem2, "push") == 0 && (atoi(tem2 = strtok(NULL, " ")) == 0) && j > 1)
                        {
                                fprintf(stderr, "L%d: usage: push integer", j);
                                exit(EXIT_FAILURE);
                        }
                        */
                        if ((tem2 = strtok(NULL, " ")) == NULL)
                                tem2 = "";
                        tipos[i].f(&stack, _atoi(tem2));
                        return (0);
                }
                i++;
        }
        return (1);
}
