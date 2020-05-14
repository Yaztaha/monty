#include "monty.h"

/**
 * pop - removes a node to the stack.
 * @stack: top node of the stack.
 * @line_n: line number.
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		errors1(7, line_n);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
