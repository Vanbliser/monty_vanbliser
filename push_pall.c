#include "monty.h"

/* Function to push an element to the stack */
void push(stack_t **stack, unsigned int line_number, char **token)
{
    int value;
    stack_t *new_node;
    if (!token || !token[1])
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    value = atoi(token[1]);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/* Function to print all values on the stack */
void pall(stack_t **stack)
{
    stack_t *current;
    if (*stack == NULL)
        return;

    current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/* Function to free the stack memory */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next = NULL;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
