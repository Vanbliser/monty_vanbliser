#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pint_instruction - pint instruction_t
 *
 * Return: pint instruction_t
 */
instruction_t pint_instruction(void)
{
	instruction_t pint_inst;

	pint_inst.opcode = "pint";
	pint_inst.f = pint;
	return (pint_inst);
}
