#include "main.h"

/**
 * environment - function the environment
 * env : double pointer
 */

void	environment(char **env)
{
	int	i;

	i = 0;
	while(env[i])
		printf("%s\n", env[i++]);
}
