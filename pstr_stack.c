#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>
int pstr_stack(stack_t **head)
{
	int character = 0, counter = 0;


	if ((*head) == NULL )
	{
		putchar('\n');
		return (1);
	}

	while ((*head))
	{
		character = (*head)->n;
		if ((character < 0 || character > 127) && counter > 0)
		{
			putchar('\n');
			return (1);
		}
		if (character == 0 && counter == 0)
			return(1);
		if (character == 0 && counter > 0)
		{
			putchar('\n');
			return (1);
		}
		putchar((*head)->n);
		*head = (*head)->next;
		counter++;
	}
	printf("\n");
	return 1;
}
