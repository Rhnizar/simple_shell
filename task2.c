#include "main.h"

/**
 * cmd_app_task2 - execute command
 * line : char pointer
 * env : double pointer
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
	if (!valid_cmd)
	{
		printf("%s: command not found\n", split[0]);
		return ;
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(valid_cmd, split, NULL) == -1)
			{
				printf("Error in execve\n");
				exit(1);
			}
			free_double_ptr(split);
		}
		else if (pid == -1)
			printf("Error the fork\n");
		else
			wait(NULL);
	}
}