#include "monty.h"
void _push(stack_t **stack, unsigned int line_number)
{
        stack_t *new_node;
        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                /*
                 * Free anything
                 */ 
                printf("Error: malloc failed");
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


void _pall(stack_t **stack, unsigned int line_number)
{
        stack_t *new_node = *stack;
        line_number = line_number;
        while (new_node != NULL)
        {
                printf("%i\n", new_node->n);
                new_node = new_node->next;
        }
}
