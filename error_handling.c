#include "monty.h"

/**
 * unknown_instruction_error - print error message to stdout and exit failure
 * @line_num: line number where the error occurred
 * @i: the unknown instruction
 * @stack: stack to be freed
 */
void unknown_instruction_error(unsigned int line_num, char *i, stack_t *stack)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, i);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * malloc_failed_error - print error message to stdout and exit failure
 * @memlist: pointer to memlist to be freed
 */
void malloc_failed_error(memlist_t *memlist)
{
	free_memlist(memlist);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - print error message to stdout and exit failure
 * @file: filename
 */
void open_file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * monty_usage_error - print error message to stdout and exit failure
 */
void monty_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
