#include "monty.h"

/**
 * select_data_structure - a function that selects a stack or queue
 * data structure
 * @flag: pointer to an unsigned int to represent the data structure.
 * if NULL, select the default which is stack.
 *
 * Return: returns 1 for stack, and 0 for queue
 */
unsigned int select_data_structure(unsigned int *flag)
{
	static unsigned int f = 1;

	if (flag != NULL)
	{
		if (*flag == 1)
			f = 1;
		else
			f = 0;
	}
	return (f);
}
