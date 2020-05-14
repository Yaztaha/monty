#include "monty.h"

/**
 * push_to_stack - adds a node to top of the stack.
 * @new_node: pointer to the new node.
 * @line_n: line number of of the opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_n)
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
