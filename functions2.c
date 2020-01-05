#include "monty.h"
/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to top
 * @line_number: integer
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	int cont = 0;

	line_number = line_number;
	cont = (*stack)->next->n - (*stack)->n;
	_pop(stack, cont);
	_pop(stack, cont);
	_push(stack, cont);
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to top
 * @line_number: integer
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack && (*stack)->next) != '\0')
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n /= (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
