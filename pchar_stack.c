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
		fprintf(stderr, "L%i: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else if (character < 0 || character > 255)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", character);
	return 1;
}
