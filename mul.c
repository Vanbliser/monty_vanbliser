#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n *= (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    free(temp);
}
