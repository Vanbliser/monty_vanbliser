#include "monty.h"

/**
 * rotl - Function to rotate the stack to the top
 * @stack: the stack
 * @line_number: line number of the operation
 */
void rotl(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	*stack = current->next;
	(*stack)->prev = NULL;

	temp->next = current;
	current->prev = temp;
	current->next = NULL;
}

/**
 * rotl_instruction - rotl instruction_t
 *
 * Return: rotl instruction_t
 */
instruction_t rotl_instruction(void)
{
	instruction_t rotl_inst;

	rotl_inst.opcode = "rotl";
	rotl_inst.f = rotl;
	return (rotl_inst);
}
