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
void	cmd_app_task2(char *line, char **env);
void	environment(char **env);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	my_exit(char *line);
void	execute_command(char *cmd, char *path, char **env);
char	*ft_strdup(char *s);

#endif

