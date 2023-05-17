
#include "main.h"

/* join a given path with a given command */
static char	*ft_join_command_path(char *path, char *cmd)
{
	char	*output;
	int		i;

	output = malloc(ft_len(cmd) + ft_len(path) + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (path && *path)
		output[i++] = *path++;
	output[i++] = '/';
	while (cmd && *cmd)
		output[i++] = *cmd++;
	output[i] = '\0';
	return (output);
}

/* get the exact command path */
char	*valid_command_path(char **paths, char *cmd)
{
	char	*command_path;

	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	else
	{
		while (*paths)
		{
			command_path = ft_join_command_path(*paths, cmd);
			if (access(command_path, F_OK) == 0)
				return (command_path);
			free(command_path);
			paths++;
		}
	}
	return (NULL);
}


// has to be handled
char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	// i think when unseting PATH it shouldn't work
	// if (*env == NULL)
	// 	*env = PATH;
	// if (!(*env))
	// 	return (NULL);
	return (ft_split(*env + 5, ':'));
}