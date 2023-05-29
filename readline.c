#include "monty.h"

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
	memlist_t *memlist = NULL;
	static int tmp3 = 1;
	size_t size = 1, size_tmp2;
	char *tmp1 = NULL, *tmp2 = NULL;

	tmp1 = malloc(1);
	tmp1[0] = '\0';
	tmp2 = malloc(64);
	if (tmp2 == NULL)
		malloc_failed_error(memlist);
	addtomemlist(&memlist, tmp2);
	if (tmp3)
	{
		while (fgets(tmp2, 64, file))
		{
			size_tmp2 = strlen(tmp2);
			reduce_multispaces_to_one(&tmp2, &size_tmp2, &memlist);
			concat(&tmp1, &tmp2, &size, &size_tmp2, &memlist);
			reduce_multispaces_to_one(&tmp1, &size, &memlist);
			if (strchr(tmp1, '\n'))
			{
				if (*line)
					free(*line);
				trim_line(&tmp1, &size, &memlist);
				*line = tmp1;
				*len = size - 1;
				return (*line);
			}
		}
		tmp3 = 0;
		if (*line)
			free(*line);
		trim_line(&tmp1, &size, &memlist);
		*line = tmp1;
		*len = size - 1;
		return (*line);
	}
	return (NULL);
}

/**
 * concat - concatenate s to d, ensure that d is resized to fit
 * @tmp1: the destination string
 * @tmp2: the source string
 * @size: length of destination
 * @size_tmp2: length of source
 * @memlist: list of previously allocated memory
 *
 * Return: a pointer to the dest
 */
char *concat(char **tmp1, char **tmp2, size_t *size,
		size_t *size_tmp2, memlist_t **memlist)
{
	char *tmp;

	*size = *size + *size_tmp2;
	tmp = *tmp1;
	*tmp1 = malloc(*size);
	if (*tmp1 == NULL)
		malloc_failed_error(*memlist);
	addtomemlist(memlist, *tmp1);
	memcpy(*tmp1, tmp, strlen(tmp));
	strcat(*tmp1, *tmp2);
	free(tmp);
	return (*tmp1);
}

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
		if (isspace(line[0][i]) && (line[0][i] != '\n'))
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
		malloc_failed_error(*memlist);
	addtomemlist(memlist, newline);
	strncpy(newline, tmpline, new_line_length);
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
	free(tmp);
}
