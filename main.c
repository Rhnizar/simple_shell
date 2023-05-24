#include "main.h"

/**
 * cmd_app - execute command
 * @line : char pointer
 */

void	cmd_app(char *line)
{
	char	**split;
	pid_t	pid;

	pid = fork();
	split = ft_split(line, ' ');
	if (pid == 0)
	{
		if (split[1])
		{
			printf("./shell: No such file or directory\n");
			exit(1);
		}
		else if (execve(split[0], split, NULL) == -1)
		{
			printf("./shell: No such file or directory\n");
			exit(1);
		}
		free_double_ptr(split);
	}
	else if (pid == -1)
		printf("Error the fork\n");
	else
		wait(NULL);
}

/**
 * main - main programme
 * @argc : arguments count
 * @argv : arguments values
 * @env : environment
 * Return: int
 */

int main(int argc, char **argv, char **env)
{
	char		*line = NULL;
	ssize_t		len_line;
	size_t		buf = 0;

	(void)argc;
	(void)argv;
	while (1)
	{
		printf("\033[0;33m simple_shell ~ ");
		printf("\033[0;37m");
		len_line = getline(&line, &buf, stdin);
		if (len_line < 0)
		{
			free(line);
			// printf("exit\n");
			return (0);
		}
		new_line(&line);
		if (line[0])
		{
			if (ft_strncmp(line, "env", 3) == 0)
				environment(env);
			// if (ft_strncmp(line, "exit", 4) == 0)
			// 	my_exit(line);
			else
				cmd_app_task2(line, env);
				cmd_app(line);
		}
	}
	free(line);
	return (0);
}

