#include "monty.h"

/**
 * pall - Function to print all values on the stack
 * @stack: the stack
 * @line_number: line number of the operation
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pall_instruction - pall instruction_t
 *
 * Return: pall instruction_t
 */
instruction_t pall_instruction(void)
{
	instruction_t pall_inst;

	pall_inst.opcode = "pall";
	pall_inst.f = pall;
	return (pall_inst);
}
