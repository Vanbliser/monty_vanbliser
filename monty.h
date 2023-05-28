#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var - global variables
 * @push_value: the value to be pushed
 * @stack: the stack
 */
typedef struct global_s
{
	int *push_value;
	stack_t *stack;
}global_t

/*Global Variables */
extern global_t __attribute__((unused)) global;

/* Helper Function Prototypes */
void free_stack(void);
void monty_usage_error(void);
void open_file_error(void);
void malloc_failed_error(void);
void unknown_instruction_error(unsigned int line_number, char *i);
void error_cleanup(void);

#endif /* MONTY_H */
