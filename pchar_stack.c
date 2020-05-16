#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>
int pchar_stack(stack_t **head, int line_number)
{
	int character = 0;


	if ((*head) == NULL )
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	character = (*head)->n;
	if (character < 0 || character > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}


		printf("%c\n", character);
	return 1;
}
