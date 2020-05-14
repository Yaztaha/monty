#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_n: line number.
 */
void add(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors1(8, line_n, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
