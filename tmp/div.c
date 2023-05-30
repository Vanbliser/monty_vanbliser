#include "monty.h"
void stack_div(stack_t **stack, unsigned int line_number)
{
    int result;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n / (*stack)->n;
    pop(stack, line_number); /* Remove the top element*/
    (*stack)->n = result;    /* Update the second top element with the result*/
}
