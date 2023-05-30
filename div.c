#include "monty.h"

/**
 * _div - divides the second top element of the stack by the
 * top element of the stack.
 * @stack: the stack
 * @line_number: line number of the operation
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number); /* Remove the top element*/
	(*stack)->n = result;	 /* Update the second top element with the result*/
}

/**
 * _div_instruction - _div instruction_t
 *
 * Return: _div instruction_t
 */
instruction_t _div_instruction(void)
{
	instruction_t _div_inst;

	_div_inst.opcode = "_div";
	_div_inst.f = _div;
	return (_div_inst);
}
