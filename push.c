#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number being executed from the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " "), *endptr = NULL;
	long s;
	int value;
	stack_t *new_node;

	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	s = strtol(arg, &endptr, 10);
	if (!(*arg != '\0' && *endptr == '\0')) /* if it's not a valid long int */
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((s > INT_MAX) || (s < INT_MIN))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
