#include "monty.h"

/**
 * reduce_multispaces_to_one - a function that reduces more than one
 * spaces to one
 * in a line
 * @line: pointer to the line
 * @len: length of the line
 * @memlist: list of previously allocated memory
 */
void reduce_multispaces_to_one(char **line, size_t *len, memlist_t **memlist)
{
	size_t i = 0, new_line_length = 0;
	char *tmpline, *newline;

	tmpline = malloc(sizeof(char) * ((*len) + 1));
	if (tmpline ==	NULL)
		malloc_failed_error(*memlist);
	addtomemlist(memlist, tmpline);
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
	newline = malloc(sizeof(char) * (new_line_length + 1));
	if (newline == NULL)
		malloc_failed_error(*memlist);
	addtomemlist(memlist, newline);
	strncpy(newline, tmpline, new_line_length + 1);
	free(tmpline);
	tmpline = *line;
	*line = newline;
	*len = new_line_length;
	free(tmpline);
}

/**
 * trim_line - a function that removes leading and trailing spaces
 * @line: the line to perform the trim on
 * @len: length of the line
 * @memlist: list of previously allocated memory
 */
void trim_line(char **line, size_t *len, memlist_t **memlist)
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
		malloc_failed_error(*memlist);
	addtomemlist(memlist, newline);
	if (new_len > 1)
		for (k = 0; i <= j; ++i, ++k)
			newline[k] = line[0][i];
	newline[k] = '\0';
	tmp = *line;
	*line = newline;
	*len = new_len - 1;
	free(tmp);
}
