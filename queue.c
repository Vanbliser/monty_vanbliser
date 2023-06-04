#include "monty.h"

/**
 * queue - Function to convert a stack to a queue
 * @stack: the stack
 * @line_number: line number of the operation
 */
void queue(stack_t __attribute__((unused)) **stack,
	 __attribute__((unused)) unsigned int line_number)
{
	unsigned int f = 0;

	(void)select_data_structure(&f);
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
