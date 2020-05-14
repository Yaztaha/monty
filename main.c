#include "monty.h"

stack_t *head = NULL;

/**
 * main - main function for monty interpreter.
 * @argc: umber of command line arguments.
 * @argv: command line arguments string.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		errors(1);
	open_file(argv[1]);
	free_node();
	return (0);
}

/**
 * create_node - create node.
 * @n: number.
 * Return: node.
 */
stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees nodes.
 */
void free_node(void)
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
