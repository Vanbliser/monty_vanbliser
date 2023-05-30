#include "monty.h"

/**
 * swap - Function to swap the top two elements of the stack
 * @stack: the stack
 * @line_number: line number of the operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;
	top->prev = *stack;
	top->next = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->next = top;
}

/**
 * swap_instruction - swap instruction_t
 *
 * Return: swap instruction_t
 */
instruction_t swap_instruction(void)
{
	instruction_t swap_inst;

	swap_inst.opcode = "swap";
	swap_inst.f = swap;
	return (swap_inst);
}
