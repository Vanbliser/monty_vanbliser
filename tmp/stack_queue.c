#include "monty.h"

int data_format = 0; /* Global variable to track data format: 0 for stack, 1 for queue*/

/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void stack_ptr(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    data_format = 0; /* Set data format to stack (LIFO)*/
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void queue_ptr(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    data_format = 1; /* Set data format to queue (FIFO)*/
}
