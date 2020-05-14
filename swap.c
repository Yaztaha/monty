#include "monty.h"

/**
 * swap - swaps top two elements of the stack.
 * @stack: stack pointer..
 * @line_n: line number.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors1(8, line_n, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
