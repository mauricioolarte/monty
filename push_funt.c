#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 *print_stack - print all the nodes of h.
 *@h: is a double linked list head.
 *Return: number of nodes.
 */
size_t print_stack(const stack_t *h)
{
	int number_nodes = 0;
	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL && number_nodes < 10)
	{
		printf("%d\n", h->n);
		h = h->next;
		number_nodes++;
	}
	return (number_nodes);
}

/**
 *print_pint - print all the nodes of h.
 *@h: is a double linked list head.
 *Return: number of nodes.
 */
size_t print_pint(const stack_t *h, int line_number)
{

	if (h == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
		printf("%d\n", h->n);
	return (line_number);
}


/**
 **push_to_stack - check the code for Holberton School students.
 *@head: is head of linked list.
 *@n: integer
 * Return: new if succes NULL if fail.
 */
stack_t *push_to_stack(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
	return (new);
}

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
