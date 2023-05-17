#include "main.h"

/**
 * free_double_ptr - function the free double pointer
 * str : double pointer
 */

void	free_double_ptr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free (str[i++]);
	free(str);
}

/**
 * ft_strlen - lenght the string
 * s : char pointer
 * Return: lenght
 */
 
size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

/**
 * new_line - new line
 * str : double pointer
 */

void new_line(char **str)
{
	int len;

	len = ft_strlen(*str) - 1;
	if ((*str)[len] == '\n')
		(*str)[len] = '\0';
}