#include "monty.h"

#define UX __attribute__((unused))

/**
 * stack - Function to convert a queue to a stack
 * @queue: the queue
 * @line_number: line number of the operation
 */
void stack(stack_t UX **queue, unsigned int UX line_number)
{
}

/**
 * stack_instruction - stack instruction_t
 *
 * Return: stack instruction_t
 */
instruction_t stack_instruction(void)
{
	instruction_t stack_inst;

	stack_inst.opcode = "stack";
	stack_inst.f = stack;
	return (stack_inst);
}
