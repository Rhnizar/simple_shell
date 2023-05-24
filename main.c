#include "main.h"

/**
 * sig_handl - Ctrl + C
 * @sig: signal
 */

void sig_handl(int sig)
{
	if (sig == SIGINT)
		write(1, "\nsimple_shell ~ ", 16);
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
	char		*path;

	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handl);
	path = getenv("PATH");
	return (0);
}
