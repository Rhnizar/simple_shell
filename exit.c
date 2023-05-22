#include "main.h"

/**
 * my_exit - funtion exit
 * @line : char pointer
 */

void	my_exit(char *line)
{
	free(line);
	printf("exit\n");
	exit(0);
}
