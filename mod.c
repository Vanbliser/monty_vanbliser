#include "monty.h"

/**
 * mod - get the modulus the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_instruction - mod instruction_t
 *
 * Return: mod instruction_t
 */
instruction_t mod_instruction(void)
{
	instruction_t mod_inst;

	mod_inst.opcode = "mod";
	mod_inst.f = mod;
	return (mod_inst);
}
