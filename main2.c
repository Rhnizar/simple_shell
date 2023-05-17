
#include "main.h"

/**
 * main - main programme
 * Return: int
 */
 
int main(int argc,  char **argv, char **env)
{
	char	**paths;
	char	*valid_cmd;
	char	*arg[] = {argv[1], NULL};
	

	if (argc < 2)
		return (0);
	paths = get_paths(env);
	valid_cmd = valid_command_path(paths, argv[1]);
	if (!valid_cmd)
		printf("%s: command not found\n", argv[1]);
	else
		execve(valid_cmd, arg, env);
	return (0);
}

