#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *current, *last;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    current = *stack;
    last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    current->prev = NULL;
}
