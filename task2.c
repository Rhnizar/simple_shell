#include "main.h"

/**
 * cmd_app_task2 - execute command
 * @line : char pointer
 * @env : double pointer
 */

void	cmd_app_task2(char *line, char **env)
{
	char	**split;
	char	**paths;
	char	*valid_cmd;
	pid_t	pid;

	split = ft_split(line, ' ');
	paths = get_paths(env);
	valid_cmd = valid_command_path(paths, split[0]);
	free_double_ptr(paths);
	if (!valid_cmd)
	{
		perror("./shell");
		free_double_ptr(split);
		return;
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(valid_cmd, split, NULL) == -1)
			{
				perror("./shell");
				free_double_ptr(split);
				exit(1);
			}
		}
		else if (pid == -1)
			perror("./shell");
		else
			wait(NULL);
		free(valid_cmd);
		free_double_ptr(split);
	}
}

