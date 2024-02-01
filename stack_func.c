#include "monty.h"

/**
 * _push - adding to the top of stack.
 *
 * @stack: pointer to the top of the stack.
 * @lint_number: number of line opcode occurs in.
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	push_arg = 0;
	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg)
		push_arg = atoi(arg);
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
		add_dnodeint_end(stack, push_arg);

	if (sq_flag == 0)
		add_dnodeint(stack, push_arg);
}

/**
 * _pall - print add functions
 *
 * @stack: pointer to stack.
 * @line_number: number of line opcode occurs on.
 *
 */

void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print int on top of stack.
 *
 * @stack: pointer to stack.
 * @line_number: number of line opcode occurs on.
 *
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (!runner)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - removes the top element of the stack.
 *
 * @stack: pointer to stack.
 * @line_number: number of line opcode occurs on.
 *
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);

}

/**
 * _swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to the stack.
 * @line_number: number of line opcode occurs on.
 *
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (!runner || !(runner->next))
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}
