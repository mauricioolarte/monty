#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE *file_bytecode;
	const char *s, *lineavoid = "\n";
	const char *delim = " \n"; /*for strtok function.*/
	char linea[1024];
	char *argument[3]; /* arguments is zise 3 for opcodes, [0] name, [1] value.;*/
	int line_number = 0, push_counter = 0, i = 1;
	stack_t *head = NULL;

	s = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_bytecode = fopen(s, "r");
	if (file_bytecode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", s);
		exit(EXIT_FAILURE);
	}
	while (fgets(linea, 1024, (FILE *) file_bytecode))
	{
		if (linea == lineavoid)
			continue;
		line_number++;
		argument[0] = strtok(linea, delim);
		if (argument[0] == NULL || strcmp(argument[0], "nop") == 0)
			continue;
		if (strcmp(argument[0], "push") == 0)
		{
			push_counter++;
			while (argument[0] != NULL && i <= 1)
			{
				i++;
				argument[1] = strtok(NULL, delim);
				if (is_integer(argument[1]) == 1)
					head = push_to_stack(&head, atoi(argument[1]));
				else
				{
					fprintf(stderr, "L%i: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			i = 1;
		}
		else if (strcmp(argument[0], "pall") == 0)
			print_stack(head);
		else if (strcmp(argument[0], "pint") == 0)
			print_pint(head, line_number);
		else if	(strcmp(argument[0], "nop") == 0)
			;
		else if (strcmp(argument[0], "pop") == 0)
			head = delete_dnodeint_at_index(&head,0, line_number);
		else if (strcmp(argument[0], "add") == 0)
		{
			add_stack(&head, line_number);
			head = delete_dnodeint_at_index(&head,0, line_number);
		}
		else if (strcmp(argument[0], "swap") == 0)
			head = swap_stack(&head, line_number);
		else
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, argument[0]);
	}
	free_stack(head);
	fclose(file_bytecode);
	return (0);
}
