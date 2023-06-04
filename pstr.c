#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void pstr(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current;
	char newline = '\n';

	current = *stack;
	if (lenofstack(current) == 0)
	{
		fprintf(stdout, "%c", newline);
	}
	else
	{
		while (current && current->n > 0 && current->n <= 127)
		{
			fprintf(stdout, "%c", current->n);
			current = current->next;
		}
		fprintf(stdout, "%c", newline);
	}
}

/**
 * pstr_instruction - pstr instruction_t
 *
 * Return: pstr instruction_t
 */
instruction_t pstr_instruction(void)
{
	instruction_t pstr_inst;

	pstr_inst.opcode = "pstr";
	pstr_inst.f = pstr;
	return (pstr_inst);
}
