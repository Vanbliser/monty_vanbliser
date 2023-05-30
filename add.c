#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}
}

/**
 * add_instruction - add instruction_t
 *
 * Return: add instruction_t
 */
instruction_t add_instruction(void)
{
	instruction_t add_inst;

	add_inst.opcode = "add";
	add_inst.f = add;
	return (add_inst);
}
