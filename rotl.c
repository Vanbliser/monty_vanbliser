#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *current, *last;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    current = *stack;
    last = *stack;

    while (last->next != NULL)
        last = last->next;

    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = current;
    current->prev = last;
    current->next = NULL;
}
