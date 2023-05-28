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
	char *filename, *opcode, *line = NULL;
	stack_t *stack = NULL;
	FILE *file;
	unsigned int line_number = 1;
	size_t len;

	if (argc != 2)
	{
		error_handler(3, NULL, 0);
		exit(EXIT_FAILURE);
	}
	else
	{
		filename = argv[1];
		file = fopen(filename, "r");
		if (!file)
		{
			error_handler(4, filename, 0);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (readline(&line, &len, file))
			{
				format_line(&line, &len); /*Remove unneccessary spaces in line*/
				if (strlen(line) > 0)
				{
					opcode = strtok(line, " "); /* Split line into tokens*/
					run(opcode, line_number, file, &stack);
					line_number++;
				}
			}
		}
		fclose(file);
		exit(EXIT_SUCCESS);
	}
}

/**
 * readline - read line by line from a file stream
 * @line: store the read line here
 * @len: store the length of the line here
 * @file: the file stream to read from
 *
 * Return: pointer to the line
 */
char *readline(char **line, size_t *len, FILE *file)
{
	static int tmp3 = 1;
	size_t size = 1;
	char *tmp, *tmp1, *tmp2;

	tmp1 = malloc(1);
	tmp1[0] = '\0';
	tmp2 = malloc(256);
	if (tmp2 == NULL)
	{
		error_handler(1, NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (tmp3)
	{
		while (fgets(tmp2, 256, file))
		{
			size = size + strlen(tmp2);
			tmp = tmp1;
			tmp1 = malloc(size);
			if (tmp1 == NULL)
			{
				error_handler(1, NULL, 0);
				exit(EXIT_FAILURE);
			}
			memcpy(tmp1, tmp, strlen(tmp));
			strcat(tmp1, tmp2);
			free(tmp);
			format_line(&tmp1, &size);
			if (strchr(tmp2, '\n'))
			{
				if(*line)
					free(*line);
				*line = tmp1;
				*len = size - 1;
				return (*line);
			}
		}
		tmp3 = 0;
		if (*line)
			free(*line);
		*line = tmp1;
		*len = size - 1;
		return (*line);
	}
	return (NULL);
}

/**
 * run - a function that run an opcode
 * @opcode: operation
 * @line_number: line number
 * @file: pointer to a FILE
 * @stack: pointer to a stack_t
 */
void run(char *opcode, unsigned int line_number, FILE *file, stack_t **stack)
{
	if (opcode)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(stack, line_number);
		}
		else
		{
			error_handler(2, opcode, line_number);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * error_handler - a function that prints error messages
 * @num: selects what message to print
 * @util: pointer to the filename or opcode
 * @line_number: the line number
 */
void error_handler(int num, char *util, unsigned int line_number)
{
	switch (num)
	{
		case 1:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 2:
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, util);
			break;
		case 3:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 4:
			fprintf(stderr, "Error: Can't open file %s\n", util);
			break;
	}
}

/**
 * format_line - a function that remove unnesseccary spaces in a line
 * @line: pointer to the line
 * @len: length of the line
 */
void format_line(char **line, size_t *len)
{
	size_t i = 0, new_line_length = 0;
	char *tmpline, *newline;

	tmpline = malloc(sizeof(char) * ((*len) + 1));
	if (tmpline ==	NULL)
	{
		error_handler(1, NULL, 0);
		exit(EXIT_FAILURE);
	}
	trim_line(line, len);/* Remove leading and trailing spaces */
	while (line[0][i] != '\0')
	{
		if (isspace(line[0][i]))
		{
			tmpline[new_line_length] = ' ';
			++new_line_length;
			while (isspace(line[0][i]))
				++i;
		}
		else
		{
			tmpline[new_line_length] = line[0][i];
			++i;
			++new_line_length;
		}
	}
	tmpline[new_line_length] = line[0][i];
	newline = malloc(sizeof(char) * new_line_length);
	if (newline == NULL)
	{
		error_handler(1, NULL, 0);
		exit(EXIT_FAILURE);
	}
	strncpy(newline, tmpline, new_line_length);
	free(tmpline);
	tmpline = *line;
	*line = newline;
	free(tmpline);
}

/**
 * trim_line - a function that removes leading and trailing spaces
 * @line: the line to perform the trim on
 * @len: length of the line
 */
void trim_line(char **line, size_t *len)
{
	char *newline, *tmp;
	size_t new_len = 0, i = 0, j = *len - 1, k = 0;

	while (isspace(line[0][i]))
		++i;
	while ((isspace(line[0][j]) || line[0][j] == '\0') && j != 0)
		--j;
	if (j < i)
		j = i;
	new_len = (line[0][i] == '\0') ? 1 : j - i + 2;
	newline = malloc(sizeof(char) * new_len);
	if (newline == NULL)
	{
		error_handler(1, NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (new_len > 1)
		for (k = 0; i <= j; ++i, ++k)
			newline[k] = line[0][i];
	newline[k] = '\0';
	tmp = *line;
	*line = newline;
	free(tmp);
}
