#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pchar_instruction - pchar instruction_t
 *
 * Return: pchar instruction_t
 */
instruction_t pchar_instruction(void)
{
	instruction_t pchar_inst;

	pchar_inst.opcode = "pchar";
	pchar_inst.f = pchar;
	return (pchar_inst);
}
