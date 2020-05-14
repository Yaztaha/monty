#include "monty.h"

/**
 * errors - display error messages.
 * @error_code: error codes.
 */

void errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
		       va_arg(ag, char *));
		break;
	case 3:
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/*
 * errors1 - more errors.
 * @error_code: error code.
 */
void errors1(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
		       va_arg(ag, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
		       va_arg(ag, int));
		break;
	case 8:
		l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
		       va_arg(ag, unsigned int));
		break;
	default:
		break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
