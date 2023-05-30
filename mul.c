#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * mul_instruction - mul instruction_t
 *
 * Return: mul instruction_t
 */
instruction_t mul_instruction(void)
{
	instruction_t mul_inst;

	mul_inst.opcode = "mul";
	mul_inst.f = mul;
	return (mul_inst);
}
