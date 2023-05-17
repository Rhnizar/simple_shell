#include "main.h"

/**
 * str_count - count the string
 * str : char pointer
 * c : char
 * Return: count
 */

static int	str_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			if (str[i] == c || str[i] == '\0')
				count++;
		}
	}
	return (count);
}

/**
 * word - word
 * str : char pointer
 * c : char
 * Return: word
 */

static char	*word(char *str, char c)
{
	int		i;
	int		count;
	int		j;
	char	*wostr;

	i = 0;
	count = 0;
	j = 0;
	while (str[i] && str[i] == c)
	i++;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	i = 0;
	wostr = malloc (sizeof(char ) * count +1);
	if (!wostr)
		return (NULL);
	while (str[i] && str[i] == c)
	i++;
	while (str[i] && str[i] != c)
		wostr[j++] = str[i++];
	wostr[j] = '\0';
	return (wostr);
}

/**
 * ft_split - double pointer string
 * str : char pointer
 * c : char
 * Return: double pointer
 */

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = malloc (sizeof(char *) * (str_count((char *)str, c) + 1));
	if (!split)
		return (NULL);
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c && j < str_count((char *)str, c))
	{
		split[j] = word((char *)&str[i], c);
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		j++;
	}
	split[j] = 0;
	return (split);
}