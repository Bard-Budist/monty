#include  "monty.h"
/**
 * callFunction - Function to call functions
 * @tmp: temporal
 * @j: J
 * Return: 1 or 0
 *
*/
int callFunction(char *tmp, int j)
{
	int i = 0;
	char *tem2;
	char deli[] = "\n\t ";

	instruction_t tipos[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"nop", _nop},
		{"swap", _swap}, {NULL, NULL}
	};
	j = j;
	tem2 = strtok(tmp, deli);
	if (tem2 == NULL)
		return (0);
	while (tipos[i].opcode != NULL)
	{
		if (strcmp(tem2, tipos[i].opcode) == 0)
		{
			tem2 = strtok(NULL, deli);
			if (tem2 == NULL)
				tem2 = "";
			else if (strcmp(tem2, "0") != 0 && _atoi(tem2) == 0
					&& strcmp(tipos[i].opcode, "pall") != 0)
			{
				free(tmp);
				fprintf(stderr, "L%i: usage: push integer\n", j);
				exit(EXIT_FAILURE);
			}
			if (strcmp(tipos[i].opcode, "pall") == 0)
				tipos[i].f(&stack, j);
			else
				tipos[i].f(&stack, _atoi(tem2));
			return (0);
		}
		i++;
	}
	return (1);
}
