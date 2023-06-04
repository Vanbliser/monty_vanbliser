#include "monty.h"

/**
 * queue - Function to convert a stack to a queue
 * @stack: the stack
 * @line_number: line number of the operation
 */
void queue(stack_t **stack, unsigned int line_number)
{
	printf("%p %u\n", (void *)stack, line_number);
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
