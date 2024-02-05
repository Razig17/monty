#include "monty.h"
#include <stdio.h>

/**
 * read_file - reads the content of the file.
 * @file: the file.
 *
 * Return: 0
 */

int read_file(FILE *file)
{
	int line_no = 0, type = 0;
	char *buff = NULL;
	size_t len;

	for (line_no = 1; getline(&buff, &len, file) != -1; line_no++)
	{
		type = tokenize(buff, line_no, type);
	}
	free(buff);

	return (0);
}

/**
 * tokenize - tokenizes a line.
 * @buff: the line.
 * @line_no: Interger representing the line number of of the opcode.
 * * @type: indecates the type of the stack_t list 0 for stack and 1 for queue.
 * Return: 0
 */

int tokenize(char *buff, int line_no, int type)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		Error(2);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (0);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	value = strtok(NULL, delim);
	find_opcode(opcode, value, line_no, type);
	return (type);
}
/**
 * call_fun - finds the wanted opcode.
 * @func: the opcode function.
 * @ln: Interger representing the line number of of the opcode.
 * @val: a string stores the value after the opcode.
 * @op: opcode name
 * @type: indecates the type of the stack_t list 0 for stack and 1 for queue.
 *
 */
void call_fun(op_func func, char *op, char *val, int ln, int type)

{
	stack_t *node;
	int sign;
	int i;

	sign = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			sign = -1;
		}
		if (val == NULL)
			Error(4, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				Error(4, ln);
		}

		node = new_node(atoi(val) * sign);
		if (type == 0)
			func(&node, ln);
		if (type == 1)
			push_to_queue(&node);
	}
	else
		func(&head, ln);
}

/**
 * push_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 *
 */
void push_to_queue(stack_t **new_node)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		Error(100);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

/**
 * find_opcode - finds the wanted opcode.
 * @opcode: opcode name.
 * @line_no: Interger representing the line number of of the opcode.
 * @value: a string stores the value after the opcode.
 * @type: indecates the type of the stack_t list 0 for stack and 1 for queue.
 */
void find_opcode(char *opcode, char *value, int line_no, int type)
{
	int i;
	int err;

	instruction_t func_list[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"nop", nop},
	    {"add", add},
	    {"sub", sub},
	    {"mod", mod},
	    {"div", _div},
	    {"mul", mul},
	    {"pchar", pchar},
	    {"pstr", pstr},
	    {"rotl", rotl},
	    {"rotr", rotr},
	    {NULL, NULL}};

	if (opcode[0] == '#')
		return;
	for (err = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_no, type);
			err = 0;
		}
	}
	if (err == 1)
	{
		Error(2, line_no, opcode);
	}
}

