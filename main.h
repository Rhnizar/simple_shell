#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

char	**ft_split(char const *str, char c);
void	free_double_ptr(char **str);
void	new_line(char **str);
size_t	ft_strlen(char *s);
char	*valid_command_path(char **paths, char *cmd);
char	**get_paths(char **env);

#endif