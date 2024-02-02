#include "monty.h"
/**
 * new_node - creates a new stack_t node .
 * @n: an integer.
 *
 * Return: the node.
 */
stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		Error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * push - push a node to the stack.
 * @new_node: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */

void push(stack_t **new_node, __attribute__((unused)) unsigned int line_no)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pall - prints all nodes of the stack.
 * @top_node: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void pall(stack_t **top_node, __attribute__((unused)) unsigned int line_no)
{
	stack_t *tmp;

	tmp = *top_node;
	if (top_node == NULL)
		exit(EXIT_FAILURE);
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
