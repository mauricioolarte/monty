#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 *free_stack - free memory of linked list.
 *@head: is head of linked list.
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 **get_dnodeint_at_index - returns the nth node of a linked list.
 *@head: is the head of linked list.
 *@index: is the nth node to return.
 *Return: nth node or null
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int node_number = 0;

	while (head != NULL)
	{
		if (node_number == index)
			return (head);
		node_number++;
		head = head->next;
	}
	return (NULL);
}
/**
 **delete_dnodeint_at_index - returns the nth node of a linked list.
 *@head: is the head of linked list.
 *@index: is the nth node to return.
 *Return: nth node or null
 */
stack_t *delete_dnodeint_at_index(stack_t **head, unsigned int index, int line_number)
{
	stack_t *nodeidx;

	nodeidx = get_dnodeint_at_index(*head, index);
	if (nodeidx == NULL || *head == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*head == nodeidx)
		*head = nodeidx->next;
	if (nodeidx->next != NULL)
		nodeidx->next->prev = nodeidx->prev;
	if (nodeidx->prev != NULL)
		nodeidx->prev->next = nodeidx->next;
	free(nodeidx);
	return (*head);
}
