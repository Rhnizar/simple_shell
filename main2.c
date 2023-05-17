
#include "main.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((((unsigned char *)s1)[i] || ((unsigned char *)s2)[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *) &s[i]);
}

char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	return (ft_split(*env + 5, ':'));
}

static char	*ft_join_command_path(char *path, char *cmd)
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

char	*valid_command_path(char **paths, char *cmd)
{
	char	*command_path;

	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	else if (ft_strchr(cmd, '/'))
		return (NULL);
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

// F_OK exist
// R_OK read
// W_OK write
// X_OK exection

// access("/usr/bin/awk", F_OK);


// /Users/rrhnizar/goinfre
// /Users/rrhnizar/goinfre/awk
// /usr/local/bin
// /usr/bin/awk
// /bin
// /usr/sbin
// /sbin
// /usr/local/munki
