#include "monty.h"
#include <stdio.h>

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
	    {NULL, NULL}};

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
			Error(3, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				Error(3, ln);
		}
		node = new_node(atoi(val) * sign);
		func(&node, ln);
	}
	else
	{
		func(&head, ln);
	}
}
