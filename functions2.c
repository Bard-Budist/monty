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

	resul = (*stack)->n / (*stack)->next->n;
	_pop(stack, line_number);
	_pop(stack, line_number);
	_push(stack, resul);
}
