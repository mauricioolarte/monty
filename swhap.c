#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


void swap_stack(stack_t **head, int line_number)
{
	int temp;

	if (head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;

}
