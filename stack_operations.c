#include "monty.h"

/**
 * lenofstack - a function that return the length
 * of a stack_t
 * @stack: the stack
 *
 * Return: the length
 */
size_t lenofstack(stack_t *stack)
{
	size_t len = 0;

	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/**
 * addtostack - a fuction the adds to stack
 * @head: double pointer to the stack
 * @n: integer to add to stack
 */
void addtostack(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_failed_error(NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

/**
 * addtostack_end - a function that adds to end of stack_t.
 * @head: double pointer to the stack
 * @n: integer value to add to stack
 */
void addtostack_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *current = *head;

	if (head == NULL)
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_failed_error(NULL);
	new->n = n;
	new->next = NULL;
	if (current == NULL)
	{
		*head = new;
		return;
	}
	else
	{
		while (current)
		{
			if (current->next == NULL)
			{
				current->next = new;
				new->prev = current;
				break;
			}
			current = current->next;
		}
	}
}

/**
 * getelement - returns the stack at index
 * @stack: the stack
 * @index: the index
 *
 * Return: stack at index or NULL if none
 */
stack_t *getelement(stack_t *stack, size_t index)
{
	size_t i = 0;

	while (stack)
	{
		if (i == index)
			return (stack);
		++i;
		stack = stack->next;
	}
	return (NULL);
}

/**
 * getstackint - get the address to the integer in stack
 * @stack: the stack
 * @index: the index position
 *
 * Return: return the address of the integer
 */
int *getstackint(stack_t *stack, size_t index)
{
	size_t i;

	while (stack)
	{
		if (i == index)
			return (&(stack->n));
		++i;
		stack = stack->next;
	}
	return (NULL);
}
