#include "monty.h"



/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */

void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_no)
{
	int num = 0;
	stack_t *tmp;


	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		num = tmp->n;

		if (num > 127 || num <= 0)
		{
			break;
		}
		printf("%c", num);
		tmp = tmp->next;
	}
	printf("\n");
}


/**
 * rotl -  rotates the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */

void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;

}




/**
 * rotr -  rotates the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */

void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;

	tmp->prev->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;

}
