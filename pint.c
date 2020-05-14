#include "monty.h"

/**
 * pint - print the top node of the stack.
 * @stack: top node of stack.
 * @line_n: line number.
 */
void pint(stack_t **stack, unsigned int line_n)
{
	if (stack == NULL || *stack == NULL)
		errors1(6, line_n);
	printf("%d\n", (*stack)->n);
}
