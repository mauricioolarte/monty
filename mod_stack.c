#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void mod_stack(stack_t **head, int line_number)
{



	if (head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L<%i>: can't mod, stack too short\n", line_number);
			exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<%i>: division by zero\n", line_number);
			exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->next->n / (*head)->n;
}
