#include "monty.h"

/**
 * error_exit = freeing the stack and exiting with failure.
 *
 * @stack: pointer to header.
 *
 */

void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - check if string is a number.
 *
 * @str: string passed.
 *
 * Return: 1 on success, 0 on failure.
 */

int isnumber(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
