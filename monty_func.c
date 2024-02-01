#include "monty.h"

/**
 * read_file - function that reads the file and runs commands.
 *
 * @filename: pathname to file
 * @stack: pointer to the top of the stack.
 *
 */

void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	size_t i = 0;
	char *line;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (!line || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (!s)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}

char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (!op_code)
		return (NULL);
	return (op_code);
}
