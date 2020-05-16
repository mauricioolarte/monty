#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>
int pchar_stack(stack_t **head, int line_number)
{
	int character = 0;

	character = (*head)->n;
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!(character > 64 && character < 90) || !(character > 96 && character < 123))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", character);
	return 1;
}
