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
        char deli[] = "\t ";
        instruction_t tipos[] ={
                {"push", _push}, {"pall", _pall}, {"pint", _pint},
                {"pop", _pop}, {"add", _add}, {"nop", _nop},
                {"swap", _swap}, {NULL, NULL}
        };
        j = j;
        printf("Estoy chequeando funciones\n");
        tem2 = strtok(tmp, deli);
        while (tipos[i].opcode != NULL)
        {
                printf("-----Voy a comparar-----%s------\n", tmp);
                if (strcmp(tem2, tipos[i].opcode) == 0)
                {
                        printf("Voy a tokenizar el comando\n");
                        tem2 = strtok(NULL, deli);
                        if (tem2 == NULL)
                                tem2 = "";
                        else if (strcmp(tem2, "0") != 0 && _atoi(tem2) == 0)
                        {
                                fprintf(stderr, "L%d: usage: push integer", j);
                                exit(EXIT_FAILURE);
                        }
                        printf("------Voy a ejecutar algo------\n");
                        if (strcmp(tipos[i].opcode, "pall") == 0)
                                tipos[i].f(&stack, j);
                        else
                                tipos[i].f(&stack, _atoi(tem2));
                        printf("------Ejecute algo------\n");
                        return (0);
                }
                i++;
        }
        return (1);
}
