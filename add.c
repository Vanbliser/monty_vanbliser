#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
