#include "monty.h"

/**
 * unknown_instruction_error - print error message to stdout and exit failure
 * @line_num: line number where the error occurred
 * @i: the unknown instruction
 * @stack: stack to be freed
 */
void unknown_instruction_error(unsigned int line_num, char *i)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, i);
	cleanup();
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
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - print error message to stdout and exit failure
 * @file: filename
 */
void open_file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * monty_usage_error - print error message to stdout and exit failure
 */
void monty_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	cleanup();
	exit(EXIT_FAILURE);
}
/**
 * cleanup - a function that cleans up memory allocation when an error occurs
 * It makes use of global variable cleanup of type cleanup_t to access
 * their pointers
 */
void cleanup()
{
	if (c.file)
		fclose(c.file);
	if (c.line)
		free(c.line);
	if (c.stack)
		free_stack(c.stack);
	if (c.instructionlist)
		destroy_init(c.instructionlist);
}
