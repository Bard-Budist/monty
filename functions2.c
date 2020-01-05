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
	int resul;

	resul = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	_pop(stack, line_number);
	_push(stack, resul);
}

/**
 * _mul - multiplies the second top element of the stack with the top element of the stack.
 * @stack: pointer
 * @line_number: the line number
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack) != '\0' || (*stack)->next != '\0')
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * modop -  computes the rest of the division of the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer
 * @line_number: the line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack) != '\0'|| (*stack)->next != '\0')
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
