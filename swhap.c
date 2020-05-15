#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


stack_t *swap_stack(stack_t **head, int line_number)
{
	stack_t *right_node;

	if (head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	right_node = (*head)->next;



	(*head)->next = (*head)->next->next;
	(*head)->prev = right_node;

	right_node->next = (*head);
	right_node->prev = NULL;

	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head);
	(*head) = right_node;

	return (*head);
}
