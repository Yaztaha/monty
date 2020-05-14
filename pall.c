#include "monty.h"

/**
 * pall_stack - Adds a node to the stack.
 * @stack: stack top's double pointer.
 * @line_n: line number.
 */
void pall_stack(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp;

	(void) line_n;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
