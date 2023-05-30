#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number of the operation
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);/* Remove the top element*/
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}
}

/**
 * sub_instruction - push instruction_t
 *
 * Return: sub instruction_t
 */
instruction_t sub_instruction(void)
{
	instruction_t sub_inst;

	sub_inst.opcode = "sub";
	sub_inst.f = sub;
	return (sub_inst);
}
