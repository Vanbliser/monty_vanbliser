#include "monty.h"

/**
 * push - Function to push an element to the stack
 * @stack: the stack
 * @line_number: line number of the operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	long int s;
	char *endptr = NULL, *value;

	value = strtok(NULL, " ");
	if (!value)
		push_error_handler(line_number);

	s = strtol(value, &endptr, 10);

	/* check if value is a valid long int number */
	if (!((*value != '\0') && (*endptr == '\0')))
		push_error_handler(line_number);

	/* check if s is a valid int number */
	if (!((s >= INT_MIN) && (s <= INT_MAX)))
		push_error_handler(line_number);

	addtostack(stack, atoi(value));
}

/**
 * push_error_handler - push error hander function
 * @line_number: line number of the operation
 */
void push_error_handler(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * push_instruction - push instruction_t
 *
 * Return: push instruction_t
 */
instruction_t push_instruction(void)
{
	instruction_t push_inst;

	push_inst.opcode = "push";
	push_inst.f = push;
	return (push_inst);
}
