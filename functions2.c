#include "monty.h"
/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to top
 * @line_number: integer
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int cont = 0;

	line_number = line_number;
	if ((*stack)->next != NULL)
	{
		cont = (*stack)->next->n - (*stack)->n;
		tmp = (*stack)->next;
		tmp->n = cont;
		free(*stack);
		tmp->prev = NULL;
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
