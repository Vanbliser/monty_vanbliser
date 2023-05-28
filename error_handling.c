#include "monty.h"

/**
 * error_cleanup - clean up after printing error message
 */
void error_cleanup(void)
{
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - print error message to stdout and exit failure
 * @line_number: line number where the error occurred
 * @i: the unknown instruction
 */
void unknown_instruction_error(unsigned int line_number, char *i)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, i);
	error_cleanup();
}

/**
 * malloc_failed_error - print error message to stdout and exit failure
 */
void malloc_failed_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	error_cleanup();
}

/**
 * open_file_error - print error message to stdout and exit failure
 */
void open_file_error(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", util);
	error_cleanup();
}

/**
 * monty_usage_error - print error message to stdout and exit failure
 */
void monty_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	error_cleanup();
}
