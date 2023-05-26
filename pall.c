#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number being executed from the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	for (current = *stack; current != NULL; current = current->next)
		printf("%d\n", current->n);
}
