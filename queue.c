#include "monty.h"

#define UX __attribute__((unused))

/**
 * queue - Function to convert a stack to a queue
 * @stack: the stack
 * @line_number: line number of the operation
 */
void queue(stack_t UX **stack, unsigned int UX line_number)
{
}

/**
 * queue_instruction - queue instruction_t
 *
 * Return: queue instruction_t
 */
instruction_t queue_instruction(void)
{
	instruction_t queue_inst;

	queue_inst.opcode = "queue";
	queue_inst.f = queue;
	return (queue_inst);
}
