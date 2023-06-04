#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instructionlist_s - doubly linked list of instruction_t
 * @instruction: the instruction
 * @prev: previous instruction
 * @next: next instruction
 */
typedef struct instructionlist_s
{
	instruction_t instruction;
	struct instructionlist_s *next;
	struct instructionlist_s *prev;
} instructionlist_t;

/**
 * struct memlist - a list that keeps track of dynamically allocated memory
 * @ptr: pointer to the allocated memory
 * @next: the next memory in the list
 * @prev: the previuos memory in the list
 */
typedef struct memlist
{
	void *ptr;
	struct memlist *prev;
	struct memlist *next;
} memlist_t;

/**
 * struct cleanup - a structure that keeps memory that requires to be freed
 * @file: FILE stream to be closed
 * @line: line to be freed
 * @stack: stack to be freed
 * @instructionlist: instructionlist_t to be freed
 */
typedef struct cleanup
{
	FILE *file;
	char *line;
	stack_t *stack;
	instructionlist_t *instructionlist;
} cleanup_t;

extern cleanup_t c;

/* create a function pointer type */
typedef void (*data_structure)(stack_t **head, const int c);

/* Operations Function Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* Helper Function Prototypes */

/* free.c */
void free_stack(stack_t *stack);
void addtomemlist(memlist_t **head, void *ptr);
void free_memlist(memlist_t *head);

/* error_handling.c */
void monty_usage_error(void);
void open_file_error(char *file);
void malloc_failed_error(memlist_t *memlist);
void unknown_instruction_error(unsigned int line_num, char *i);
void cleanup(void);

/* line_formatting.c */
void reduce_multispaces_to_one(char **line, size_t *len);
void trim_line(char **line, size_t *len);

/* stack_operations.c */
size_t lenofstack(stack_t *stack);
void addtostack_end(stack_t **head, const int n);
void addtostack(stack_t **head, const int n);
stack_t *getelement(stack_t *stack, size_t index);
int *getstackint(stack_t *stack, size_t index);

/* push.c */
void push_error_handler(unsigned int line_number);

/* pop.c */
void pop_error_handler(unsigned int line_number);

/* select_data_structure.c */
unsigned int select_data_structure(unsigned int *flag);

/*instructions*/
instruction_t push_instruction(void);
instruction_t pop_instruction(void);
instruction_t pstr_instruction(void);
instruction_t pall_instruction(void);
instruction_t rotl_instruction(void);
instruction_t rotr_instruction(void);
instruction_t sub_instruction(void);
instruction_t swap_instruction(void);
instruction_t add_instruction(void);
instruction_t _div_instruction(void);
instruction_t mul_instruction(void);
instruction_t nop_instruction(void);
instruction_t pchar_instruction(void);
instruction_t pint_instruction(void);
instruction_t mod_instruction(void);
instruction_t stack_instruction(void);
instruction_t queue_instruction(void);

/* init.c */
void init(instructionlist_t **inst_list);
void addinstruction(instructionlist_t **inst_list, instruction_t inst);
void destroy_init(instructionlist_t *head);

#endif /* MONTY_H */
