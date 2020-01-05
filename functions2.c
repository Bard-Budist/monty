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
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
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
