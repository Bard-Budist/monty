#include "monty.h"
/**
 * _push - push
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);

	}
	new_node->n = line_number;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		(*stack) = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		(*stack) = new_node;
	}
}
/**
 * _pall - pall
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;

	if (stack != NULL || *stack != NULL)
	{
		line_number = line_number;
		while (new_node != NULL)
		{
			printf("%i\n", new_node->n);
			new_node = new_node->next;
		}
	}
}
/**
 * _pop - pop
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		free(tmp);
		*stack = NULL;
	}
}
/**
 * _swap - swap
 * @stack: Stack
 * @line_number: Line number
 *
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * _add - add
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *temp;

	temp = (*stack);

	while (temp)
	{
		i++;
		temp = temp->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too sstackort\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next->n += (*stack)->n;
	free(*stack);
	temp->prev = NULL;
	(*stack) = temp;
}
