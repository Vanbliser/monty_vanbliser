#include "monty.h"

cleanup_t c = {NULL, NULL, NULL, NULL};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char **argv)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	instructionlist_t *current;

	if (argc != 2)
		monty_usage_error();
	c.file = fopen(argv[1], "r");
	if (c.file == NULL)
		open_file_error(argv[1]);
	init(&(c.instructionlist));	/* initialize the instruction list */
	current = c.instructionlist;
	while ((nread = getline(&(c.line), &len, c.file)) != -1)
	{
		line_number++;
		reduce_multispaces_to_one(&(c.line), &len);
		trim_line(&(c.line), &len);
		opcode = strtok(c.line, " ");
		if (opcode)
			while (current)
			{
				if (strcmp(opcode, current->instruction.opcode) == 0)
				{
					current->instruction.f(&(c.stack), line_number);
					break;
				}
				current = current->next;
				if (current == NULL)
					unknown_instruction_error(line_number, opcode);
			}
		current = c.instructionlist; /* return current to the start */
	}
	cleanup();
	exit(EXIT_SUCCESS);
}
