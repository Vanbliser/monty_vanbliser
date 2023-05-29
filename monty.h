#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

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
 * struct memlist - a list that keeps track of dynamically allocated memory
 * @ptr: pointer to the allocated memory
 * @next: the next memory in the list
 */
typedef struct memlist
{
    char *ptr;
	struct memlist *prev;
    struct memlist *next;
} memlist_t;

/*Global Variables */
extern int push_value;

/* Helper Function Prototypes */
void free_stack(stack_t *stack);
memlist_t *addtomemlist(memlist_t **head, char *ptr);
void free_memlist(memlist_t *head);
void monty_usage_error(void);
void open_file_error(char *file);
void malloc_failed_error(memlist_t *memlist);
void unknown_instruction_error(unsigned int line_number, char *i, stack_t *stack);
void error_cleanup(void);
void trim_line(char **line, size_t *len, memlist_t **memlist);
void reduce_multispaces_to_one(char **line, size_t *len, memlist_t **memlist);
char *concat(char **tmp1, char **tmp2, size_t *size, 
		size_t *size_tmp2, memlist_t **memlist);
char *readline(char **line, size_t *len, FILE *file);

#endif /* MONTY_H */
