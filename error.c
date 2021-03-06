#include "shell.h"
/**
 * not_found - sends an error message when location is nor found
 * @argv0:name of the program
 * @cmd0: the first command
 * @cmd_counter: command counter
 * @head: head of the list
 */
void not_found(char *argv0, char *cmd0, int cmd_counter, garbage **head)
{
	char *str = NULL, *counter = NULL;

	str = malloc(256 * sizeof(char));
	add_nodeint_end(head, str);
	_strcpy(str, argv0);
	_strcat(str, ": ");
	counter = return_integer(cmd_counter);
	_strcat(str, counter);
	_strcat(str, ": ");
	free(counter);
	_strcat(str, cmd0);
	_strcat(str, ": not found\n");
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * null_env - checks if the environ == NULL
 *
 */
void null_env(void)
{
	if (*environ == NULL)
		*environ = getcwd(NULL, 0);
}
