#include "monty.h"

/**
 * init - a function that initializes an instructionlist_t
 * @inst_list: the instructionlist_t to initialize
 */
void init(instructionlist_t **inst_list)
{
	addinstruction(inst_list, push_instruction());
	addinstruction(inst_list, pall_instruction());
}

/**
 * addinstruction - a function that adds an instruction_t to an
 * instructionlist_t
 * @inst_list: the instructionlist_t
 * @inst: the instruction
 */
void addinstruction(instructionlist_t **inst_list, instruction_t inst)
{
	instructionlist_t *new;

	if (inst_list == NULL)
		return;
	new = malloc(sizeof(instructionlist_t));
	if (new == NULL)
		malloc_failed_error(NULL);
	new->instruction = inst;
	new->prev = NULL;
	new->next = *inst_list;
	if (*inst_list != NULL)
		(*inst_list)->prev = new;
	*inst_list = new;
}

/**
 * destroy_init - a function that frees an instructionlist_t
 * @head: pointer to the instructionlist_t
 */
void destroy_init(instructionlist_t *head)
{
	instructionlist_t *prev;

	if (head != NULL)
	{
		while (head->next)
		{
			prev = head;
			head = head->next;
			free(prev);
		}
		free(head);
	}
}
