#include <stdio.h>
#include <string.h>

int is_integer(char *str)
{
	unsigned int i;
	int valor;

	if (str == NULL)
		return (0);
	for(i=0; i < strlen(str); i++)
	{
		if (str[0] == '-')/* validation if negative number*/
		    continue;
		else
		{
			valor = str[ i ] - '0';
			if(valor < 0 || valor > 9)
				return 0;
		}
	}
	return 1;
}
