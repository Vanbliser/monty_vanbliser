#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: The stack
 * @line_number: Line number of the operation
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}

	last->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
 * rotr_instruction - rotl instruction_t
 *
 * Return: rotr instruction_t
 */
instruction_t rotr_instruction(void)
{
	instruction_t rotr_inst;

	rotr_inst.opcode = "rotr";
	rotr_inst.f = rotr;
	return (rotr_inst);
}
