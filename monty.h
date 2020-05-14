#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - opcoode and its function
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

/*op_code*/
typedef void (*op_func)(stack_t **, unsigned int);


/*main.c*/
stack_t *new_node(int n);
void free_node(void);

/*errors_handling*/
void errors(int error_code, ...);
void errors1(int error_code, ...);

/*file_open_read*/
void open_file(char *file_name);
void read_file(FILE *fd);
int line_interpret(char *lineptr, int line_number, int format);

/*function_call*/
void f_func(char *opcode, char *data, int n, int f);
void fun_call(op_func f, char *op, char *val, int ln, int format);

/*add_queue*/
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int line_n);

/*push*/
void pushstack(stack_t **new_node, __attribute__((unused))unsigned int line_n);

/*pall*/
void pall_stack(stack_t **stack, unsigned int line_n);

/*pint*/
void pint(stack_t **stack, unsigned int line_n);

/*pop*/
void pop(stack_t **stack, unsigned int line_n);

/*swap*/
void swap(stack_t **stack, unsigned int line_n);

/*add*/
void add(stack_t **stack, unsigned int line_n);

/*nop*/
void nop(stack_t **stack, unsigned int line_n);

#endif
