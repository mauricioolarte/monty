#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 *print_dlistint - print all the nodes of h.
 *@h: is a double linked list head.
 *Return: number of nodes.
 */
size_t print_stack(const stack_t *h)
{
	int number_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		number_nodes++;
	}
	return (number_nodes);
}



/**
 **add_dnodeint - check the code for Holberton School students.
 *@head: is head of linked list.
 *@n: integer
 * Return: new if succes NULL if fail.
 */
stack_t *push_to_stack(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
	return (new);
}
