#include "monty.h"
#include "swap.c"
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	ssize_t nread;
	unsigned int line_number = 0;
	
	instructionlist_t *instructionlist = NULL, *head;
	

	if (argc != 2)
		monty_usage_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		open_file_error(argv[1]);
	init(&instructionlist);	/* initialize the instruction list */
	head = instructionlist;
	while ((nread = getline(&line, &len, file)) != -1)
	{
		line_number++;
		reduce_multispaces_to_one(&line, &len);
		trim_line(&line, &len);
		opcode = strtok(line, " ");
		if (opcode)
			while (instructionlist)
			{
				if (strcmp(opcode, instructionlist->instruction.opcode) == 0)
				{
					instructionlist->instruction.f(&stack, line_number);
					break;
				}
				instructionlist = instructionlist->next;
				if (instructionlist == NULL)
					unknown_instruction_error(line_number, opcode, stack);
			}
		else if (strcmp(opcode, "rotr") == 0)
		{
    			rotr(&stack, line_number);
		}

		instructionlist = head;
	}
	
	fclose(file);
	free_stack(stack);
	destroy_init(instructionlist);
	exit(EXIT_SUCCESS);
}
