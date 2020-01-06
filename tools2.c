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
	int i = 0, retorno;
	char *tem2;
	char deli[] = "\n\t ";

	instruction_t tipos[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"nop", _nop},
		{"swap", _swap}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar}, {NULL, NULL}
	};
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
			if (strcmp(tipos[i].opcode, "push") == 0 && checkChar(tem2) == 1)
				return (2);
			retorno = validateReturns(tipos[i].opcode, &stack);
			if (retorno != 0)
				return (retorno);
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
/**
 * checkChar - Check char
 * @string: String
 * Return: Number
*/
int checkChar(char *string)
{
	int i = 0;
	char s;

	while (string[i] != '\0')
	{
		s = string[i];
		if (s >= 48 && s <= 57)
		{
			i++;
			continue;
		}
		else
			return (1);
	}
	return (0);
}
/**
 * validateReturns - Valida el retorno
 * @string: String to compare
 * @stack: stack
 * Return: error number
 *
*/
int validateReturns(char *string, stack_t **stack)
{
	int len = 0;
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	if (strcmp(string, "pint") == 0 && *stack == NULL)
		return (3);
	else if (strcmp(string, "pop") == 0 && *stack == NULL)
		return (4);
	else if (strcmp(string, "swap") == 0 && len < 2)
		return (5);
	else if (strcmp(string, "add") == 0 && len < 2)
		return (6);
	else if (strcmp(string, "sub") == 0 && len < 2)
		return (7);
	else if (strcmp(string, "div") == 0 && len < 2)
		return (8);
	else if (strcmp(string, "div") == 0 && (*stack)->n == 0
			&& len >= 2)
		return (9);
	else if (strcmp(string, "mul") == 0 && len < 2)
		return (10);
	else if (strcmp(string, "mod") == 0 && len < 2)
		return (11);
	else if (strcmp(string, "mod") == 0 && (*stack)->n == 0
			&& len >= 2)
		return (12);
	else if (strcmp(string, "pchar") == 0 && *stack == NULL)
		return (13);
	else if (strcmp(string, "pchar") == 0 && ((*stack)->n < 0
			|| (*stack)->n > 127) && stack != NULL)
		return (14);
	else
		return (0);
}
