#include "monty.h"

/**
 * free_dlistint - function that frees a listint_t list.
 *
 * @head: header.
 *
 * Return: no return.
 */

void free_dlistint(stack_t *head)
{
	stack_t *current;

	current = head;
	while ((current = head))
	{
		head = head->next;
		free(current);
	}
}


/**
 * delete_dnodeint_at_index - a function that deletes
 * the node at index index of a listint_t linked list.
 *
 * @head: header.
 * @index: index.
 *
 * Return: 1 if it succeeded, -1 if it failed.
*/

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *current;

	current = *head;
	while (current)
	{
		if (i == index)
		{
			if (!(current->prev) & !(current->next))
			{
				*head = NULL;
			}
			else if (!(current->prev))
			{
				current->next->prev = NULL;
				*head = current->next;
			}
			else if (!(current->next))
			{
				current->prev->next = NULL;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			free(current);
			return (1);
		}
		i++;
		current = current->next;
	}
	return (-1);

}


/**
 * add_dnodeint_end -  function that adds a new node
 * at the end of a listint_t list.
 *
 * @head: header.
 * @n: data.
 *
 * Return: the address of the new element, or NULL if it failed.
*/

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_dnodeint - function that adds a new node
 * at the beginning of a listint_t list.
 *
 * @head: header.
 * @n: data.
 *
 * Return: the address of the new element, or NULL if it failed.
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
