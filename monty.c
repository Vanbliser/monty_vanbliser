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
	char *line = NULL, *opcode = NULL, __attribute__ ((unused)) *push_value = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	ssize_t nread;
	memlist_t *memlist = NULL;

	if (argc != 2)
		monty_usage_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		open_file_error(argv[1]);
	while ((nread = getline(&line, &len, file)) != -1)
	{
		reduce_multispaces_to_one(&line, &len, &memlist);
		trim_line(&line, &len, &memlist);
		opcode = strtok(line, " ");
		push_value = strtok(NULL, " ");
		if (opcode)
		{
			printf("opcode=:%s:, value=", opcode);
			if (push_value)
				printf("%s\n", push_value);
			else
				printf("NULL\n");
		}
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
