#include "monty.h"

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


