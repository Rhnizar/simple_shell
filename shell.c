
#include "main.h"

/**
 * ft_strdup -strdup
 * @s : char pointer
 *Return : char pointer 
 */

char *ft_strdup(char *s)
{
	int size = ft_strlen(s) + 1;
	char *copy;
	int i = 0;

	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/**
 * execute_command exec cmd
 * @cmd : command
 * @path : path
 * @env : env
 */

void execute_command(char *cmd, char *path, char **env)
{
	char **split;

	int pid;
	split = ft_split(cmd, ' ');
	if (!split[0])
	{
		free_double_ptr(split);
		free(path);
		free(cmd);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(split[0], split, env) == -1)
		{
			perror("./shell");
			free_double_ptr(split);
			free(cmd);
			free(path);
			exit(15);
		}
	}
	else if (pid < 0)
		perror("fork error");
	else
		wait(NULL);
	free_double_ptr(split);
	free(cmd);
	free(path);
}
