#include "monty.h"

/**
 * free_stack - a function that frees a stack.
 * @stack: the stack to be freed
 */
void free_stack(stack_t *stack)
{
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

/**
 * free_memlist - a function that frees a memlist_t list.
 * @head: pointer the memlist
 */
void free_memlist(memlist_t __attribute__ ((unused)) *head)
{
	memlist_t *prev;

	if (head != NULL)
	{
		while (head->next)
		{
			prev = head;
			head = head->next;
			free(prev->ptr);
			free(prev);
		}
		free(head);
	}
}

/**
 * addtomemlist - a function that adds to a memlist_t
 * @head: double pointer to the list
 * @ptr: pointer to allocated memory
 *
 * Return: the address of the new element, or NULL if it failed
 */
void addtomemlist(memlist_t **head, void *ptr)
{
	memlist_t *new;

	if (head == NULL)
		return;
	new = malloc(sizeof(memlist_t));
	if (new == NULL)
		malloc_failed_error(*head);
	new->ptr = ptr;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
