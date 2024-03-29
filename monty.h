#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

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

void call_fun(op_func func, char *op, char *val, int ln, int type);
void Error(int i, ...);
int read_file(FILE *file);
int tokenize(char *buff, int line_no, int type);
void find_opcode(char *opcode, char *value, int line_no, int type);

void push_to_queue(stack_t **new_node);
void free_nodes(void);
stack_t *new_node(int n);
void push(stack_t **new_node, __attribute__((unused)) unsigned int line_no);
void pall(stack_t **head, __attribute__((unused)) unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void _div(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_no);
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_no);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_no);

#endif
