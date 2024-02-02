#include "monty.h"
stack_t *head = NULL;


/**
 * main - monty program
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	if (argc != 2)
		Error(0);
	file = fopen(argv[1], "r");
	
	if (file == NULL)
	{

		Error(1, argv[1]);
	}
	read_file(file);
	fclose(file);
	free_nodes();

	return (0);
}
/**
 * error - Prints appropiate error messages determined by their error code.
 * @i: The error code:
 *
 */

void Error(int i, ...)
{
	va_list arg;
	int num;
	char *str;

	va_start(arg, i);
	if (i == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (i == 1)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
	else if (i == 3)
		fprintf(stderr, "Error: malloc failed\n");
	else if (i == 4)
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
	else if (i == 5)
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
	else if (i == 6)
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
	
	if  (i == 2)
	{
		num = va_arg(arg, int);
		str = va_arg(arg, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", num, str);
		free(str);
	}

	
	free_nodes();
	exit(EXIT_FAILURE);
}

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
