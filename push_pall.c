#include "monty.h"

/* Function to push an element to the stack */
void push(stack_t **stack, unsigned int line_number, char **token)
{
    int value;
    char *arg;
    stack_t *new_node;
    arg = strtok(NULL, " \t\n");
    /*if (!token || !token[1])*/
    if (arg == NULL || !is_numeric(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        /*free_stack(*stack);*/
        exit(EXIT_FAILURE);
    }

    value = atoi(token[1]);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        /*free_stack(*stack);*/
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
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *current;
    (void)line_number; /*unused parameter*/
    
    /*if (*stack == NULL)
        return;*/

    current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}


int is_numeric(const char *str)
{
    int i;
    if (str == NULL || *str == '\0')
        return 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}
/* Function to free the stack memory */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next; /* = NULL;*/

    if (stack)
    {
	    next = stack->next;

    	while (current)
    	{
        /*next = current->next;*/
        	free(current);
        	current = next;

		if (next)
			next = next->next;
	}
    }
}
