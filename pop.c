#include "monty.h"

/**
 * pop - Function to remove the top element of the stack
 * @stack: the stack
 * @line_number: line number of the operation
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	if (*stack == NULL)
		pop_error_handler(line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}

void pop_error_handler(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	cleanup();
	exit(EXIT_FAILURE);
}

/*pop instruction*/
instruction_t pop_instruction(void)
{
	instruction_t pop_inst;

	pop_inst.opcode = "pop";
	pop_inst.f = pop;
	return (pop_inst);
}
