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
		printf("USAGE: monty file\n");
		break;
	case 2:
		printf("Error: Can't open file %s\n",
		       va_arg(ag, char *));
		break;
	case 3:
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		printf("L%d: unknown instruction %s\n", l_num, op);
		break;
	case 4:
		printf("Error: malloc failed\n");
		break;
	case 5:
		printf("L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
