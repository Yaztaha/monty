#include "monty.h"

/**
 * add_in_queue - adds a node to the queue.
 * @new_node: pointer to the new node.
 * @ine_ln: line number.
 */
void add_in_queue(stack_t **new_node, __attribute__((unused))unsigned int line_n)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
