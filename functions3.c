#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: point stack
 * @line_number: number of line
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	line_number = line_number;
	while (tmp)
	{
		if ((tmp->n > 0) && tmp->n < 127)
		{
			putchar(tmp->n);
			tmp = tmp->next;
		} else
			break;
	}
	putchar('\n');
}

