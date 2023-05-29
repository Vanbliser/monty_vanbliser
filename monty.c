#include "monty.h"

/**
 * main - Begin execution
 * @argc: number of arugument passed
 * @argv: array of arguments
 *
 * Return: 0 on successful
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len;
	int __attribute__ ((unused)) push_value;
	stack_t *stack = NULL;
	
	if (argc != 2)
		monty_usage_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		open_file_error(argv[1]);
	while (readline(&line, &len, file))
	{
		printf("%s\n", line);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
