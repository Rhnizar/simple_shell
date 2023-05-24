#include "main.h"

/**
 * ft_strncmp - comapre two strings
 * @s1 : char pointer
 * @s2 : char pointer
 * @n : number
 * Return: n
 */

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * ft_strchr - cherch in string
 * @s : char pointer
 * @c : int
 * Return: char pointer
 */

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}

/**
 * get_paths - get paths
 * @env : envirement
 * Return: doubel pointer
 */

char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	return (ft_split(*env + 5, ':'));
}

/**
 * ft_join_command_path - join cmd in path
 * @path : char pointer
 * @cmd : char pointer
 * Return: char pointer
 */

char	*ft_join_command_path(char *path, char *cmd)
{
	char	*output;
	int		i;

	output = malloc(ft_strlen(cmd) + ft_strlen(path) + 2);
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

/**
 * valid_command_path - valid cmd path
 * @paths : double pointer
 * @cmd : char pointer
 * Return: doubel pointer
 */

char	*valid_command_path(char **paths, char *cmd)
{
	char	*command_path;

	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	else if (ft_strchr(cmd, '/'))
		return (NULL);
	while (*paths)
	{
		command_path = ft_join_command_path(*paths, cmd);
		if (access(command_path, F_OK) == 0)
		{
			free(cmd);
			return (command_path);
		}
		free(command_path);
		paths++;
	}
	free(cmd);
	return (NULL);
}

