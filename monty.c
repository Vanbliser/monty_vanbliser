#include "monty.h"

/**
 * main - Begin execution
 * @argc: number of arugument passed
 * @argv: array of arguments
 *
 * Return: 0 on successful
 */
int main(int argc, char *argv[])
{
	char *filename, *opcode, *value;
	stack_t *stack = NULL;
	FILE *file;
	char line[256];
	unsigned int line_number = 1;

	if (argc != 2)
		print_error_messages(3, NULL, NULL, 0);
	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
		print_error_messages(4, NULL, filename, 0);
	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';  /*Remove newline character*/
		opcode = strtok(line, " ");/* Split line into tokens*/
		value = strtok(NULL, " ");
		if (strtok(NULL, " "))
			print_error_messages(1, NULL, NULL, line_number);
		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
				push(&stack, value, line_number);
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number);
			else
				print_error_messages(2, file, opcode, line_number);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}

void print_error_messages(int num, FILE *file,
		char *filename_or_opcode, unsigned int line_number)
{
	switch (num)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 2:
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, filename_or_opcode);
			fclose(file);
			break;
		case 3:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 4:
			fprintf(stderr, "Error: Can't open file %s\n", filename_or_opcode);
			break;
	}
	exit(EXIT_FAILURE);
}
