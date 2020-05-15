#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int is_coment(char *s)
{

	if (s[0] == '#')
		return(1);
	return (0);
}
