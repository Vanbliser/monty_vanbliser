#include "monty.h"

/**
 * error_cleanup - clean up after printing error message
 */
void _exit(void)
{
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - print error message to stdout and exit failure
 * @line_number: line number where the error occurred
 * @i: the unknown instruction
 */
void unknown_instruction_error(unsigned int line_number, char *i, stack_t *stack)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, i);
	free_stack(stack);
	_exit();
}

/**
 * malloc_failed_error - print error message to stdout and exit failure
 */
void malloc_failed_error(memlist_t *memlist)
{
	free_memlist(memlist);
	fprintf(stderr, "Error: malloc failed\n");
	_exit();
}

/**
 * open_file_error - print error message to stdout and exit failure
 */
void open_file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	_exit();
}

/**
 * monty_usage_error - print error message to stdout and exit failure
 */
void monty_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	_exit();
}
