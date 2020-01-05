#include "monty.h"
#include <stdio.h>
/**
 * _atoi - of string to integer
 * @s: convert
 * Return: s
*/
int _atoi(char *s)
{
	int a = 0, b = 0, c;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == '-')
			b++;
		if (s[c] > 47 && s[c] < 58)
		{
			while (s[c] > 47 && s[c] < 58)
				a = a * 10 - (s[c++] - 48);
			break;
		}
	}
	return (a *= b % 2 == 0 ? -1 : 1);
}
/**
 * free_dlistint - Free list
 * @head: Head
*/
void free_dlistint(stack_t *head)
{
	while (head != NULL)
	{
		free(head);
		head = head->next;
	}
	free(head);
}
/**
 * sum_2 - Suma 2
 * @stack: Stack
 *
*/
void sum_2(stack_t **stack)
{
	int n1 = 0, n2 = 0;

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	n1 = n1 + n2;

	_pop(stack, 0);
	_pop(stack, 0);
	_push(stack, n1);
}
/**
 * _nop -  Nop
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
/**
 * _pint - pint
 * @stack: Stack
 * @line_number: Line number
 *
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
