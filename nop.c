#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * nop_instruction - nop instruction_t
 *
 * Return: nop instruction_t
 */
instruction_t nop_instruction(void)
{
	instruction_t nop_inst;

	nop_inst.opcode = "nop";
	nop_inst.f = nop;
	return (nop_inst);
}
