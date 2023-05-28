#include "monty.h"

/**
 * free_stack - a function that frees a stack.
 */
void free_stack(void)
{
	stack_t *stack = global.stack;
	stack_t *prev;

	if (stack != NULL)
	{
		while (stack->next)
		{
			prev = stack;
			stack = stack->next;
			free(prev);
		}
		free(stack);
	}
}
