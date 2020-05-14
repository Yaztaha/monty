#include "monty.h"

/**
 * open_file - pens a file.
 * @file_name: name of the file.
 */

void open_file(char *file_name)
{
	int file_av;
	FILE *fd;

	if (file_name == NULL)
		errors(2, file_name);
	file_av = access(file_name, R_OK);
	if (file_av == -1)
		errors(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		errors(2, file_name);
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads the content of a file line by line.
 * @fd: file descriptor.
 */

void read_file(FILE *fd)
{
	int line_n;
	int fo;
	char *line;
	size_t n;

	line = NULL;
	n = 0;
	fo = 0;

	if (fd == NULL)
		errors(2, "file_name");

	for (line_n = 1; getline(&line, &n, fd) != EOF; line_n++)
	{
		fo = line_interpret(line, line_n, fo);
	}
	free(line);
}

/**
 * line_interpret - tokenize lines to call appropriate function.
 * @lineptr: line pointer in a file.
 * @line_number: line number of the function/opcode.
 * @format: format specifier.
 * Return: return 0 or 1.
 */
int line_interpret(char *lineptr, int line_number, int format)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		errors(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	f_func(opcode, value, line_number, format);
	return (format);
}
