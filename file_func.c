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
	int line_no = 0;
	char *buff = NULL;
	size_t len;

	for (line_no = 1; getline(&buff, &len, file) != -1; line_no++)
	{
		tokenize(buff, line_no);
	}
	free(buff);

	return (0);
}

/**
 * tokenize - tokenizes a line.
 * @buff: the line.
 * @line_no: Interger representing the line number of of the opcode.
 * Return: 0
 */

int tokenize(char *buff, int line_no)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		Error(2);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (0);
	value = strtok(NULL, delim);
	find_opcode(opcode, value, line_no);
	return (0);
}
/**
 * call_fun - finds the wanted opcode.
 * @func: the opcode function.
 * @ln: Interger representing the line number of of the opcode.
 * @val: a string stores the value after the opcode.
 * @op: opcode name
 *
 */
void call_fun(op_func func, char *op, char *val, int ln)

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
		func(&node, ln);
	}
	else
		func(&head, ln);
}





/**
 * find_opcode - finds the wanted opcode.
 * @opcode: opcode name.
 * @line_no: Interger representing the line number of of the opcode.
 * @value: a string stores the value after the opcode.
 */
void find_opcode(char *opcode, char *value, int line_no)
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
			call_fun(func_list[i].f, opcode, value, line_no);
			err = 0;
		}
	}
	if (err == 1)
	{
		Error(2, line_no, opcode);
	}
}


