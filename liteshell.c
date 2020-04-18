#include "shell.h"
/**
 * sig_handler - handles de Cntrl+C signal
 * @n: non used
 **/
void sig_handler (int __attribute__((unused)) n)
{
	write(STDOUT_FILENO, "\n$", 2);
}
/**
 * main - liteshell command interpreter
 * @c: argument counter
 * @argv: argument vector
 * @e: environment variables
 * Return: 0 on success, 1 if it fails
 **/

int main(int __attribute__((unused)) c, char **argv, char **e)
{
	char *line = NULL, *pat = NULL, **cm = NULL, *loc = NULL, **dirs = NULL;
	size_t size = IP_SIZE;
	ssize_t fd_line = 0;
	garbage *h = NULL;
	pid_t pid = 0;
	int chk_adr = 0, cmd_counter = 0;

	signal(SIGINT, sig_handler);
	while (_strcmp(line, SH_KILLER) != 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$>", 2);
		fd_line = getline(&line, &size, stdin), cmd_counter++;
		if (check_malloc(line) == 1)
			continue;
		if (fd_line == -1)
			free_list(h), free(line), exit(0);
		cm = tokenizer(line, &h), chk_adr = is_address(cm[0]);
		if (chk_adr != 0)
		{
			pat = path_finder(e, &h), dirs = tokenizer(pat, &h);
			loc = cat_cmd(cm[0], dirs, &h);
			if (_strcmp(loc, "sh") == 0)
				continue;
			if (loc == NULL && (_strcmp(SH_KILLER, line) == 0))
				continue;
		}
		else
			loc = cm[0];
		if (loc != NULL)
		{
			pid = fork(), wait(NULL);
			if (pid == 0)
				execve(loc, cm, e), exit(0);
		}
		else
			not_found(argv[0], cm[0], cmd_counter, &h);
	}
	free_list(h), free(line);
	return (0);
}
