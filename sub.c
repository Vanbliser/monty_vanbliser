#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int result;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n - (*stack)->n;
    pop(stack, line_number); /* Remove the top element*/
    (*stack)->n = result;    /* Update the second top element with the result*/
}
