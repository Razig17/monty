#include "monty.h"



/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */

void pstr(stack_t **stack, unsigned int line_no)
{
	int num;
	stack_t *tmp;

	(void)line_no;

	if (*stack == NULL || !((*stack)->n))
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		num = tmp->n;
		
		if (num > 127 || num == 0)
		{
			printf("\n");
			break;
		}
		printf("%c", num);
		tmp = tmp->next;
	}
}
