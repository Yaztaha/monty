#include "monty.h"
/**
 * f_func - finds the appropite function.
 * @opcode: The operation code.
 * @data: given data.
 * @n: line number.
 * @f: format specifier.
 */
void f_func(char *opcode, char *data, int n, int f)
{
	int i;
	int fl;

	instruction_t op_list[] = {
		{"push", pushstack},
		{"pall", pall_stack},
		{"pint", pint},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fl = 1, i = 0; op_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
		{
			fun_call(op_list[i].f, opcode, data, n, f);
			fl = 0;
		}
	}
	if (fl == 1)
		errors(3, n, opcode);
}

/**
 * fun_call - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string with a numeric value.
 * @ln: line numeber.
 * @format: format specifier.
 */
void fun_call(op_func f, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = new_node(atoi(val) * flag);
		if (format == 0)
			f(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		f(&head, ln);
}
