#include "shell.h"

/**
 * cat_cmd - concatenates a command
 * @cmd0: command to concatenate
 * @dirs: directories
 * @head: head of the list to malloc and to free
 * Return: pointer to concatenation
 **/

char *cat_cmd(char *cmd0, char **dirs, garbage **head)
{
	char *slash = "/";
	char *str = NULL;
	int i = 1;
	struct stat fileStat;

	if (cmd0 == NULL || (_strcmp(cmd0, ".") == 0))
	{
		return ("sh");
	}
	str = malloc(256 * sizeof(char));
	add_nodeint_end(head, str);
	if (check_malloc(str) == 1)
		return (NULL);
	for (i = 1; dirs[i]; i++)
	{
		_strcpy(str, dirs[i]);
		_strcat(str, slash);
		_strcat(str, cmd0);
		if (stat(str, &fileStat) == 0)
		{
			return (str);
		}
	}
	return (NULL);
}
/**
 * tokenizer - returns a matrix of a strtoked string
 * @line: string to tokenize
 * @head: head of the list to malloc and to free
 * Return: A double pointer containing the splied string by delimiters
 */
char **tokenizer(char *line, garbage **head)
{
	char **argv = NULL;
	char *argc = NULL;
	char *writer = NULL;
	char *linecpy = NULL;
	char *linecpy2 = NULL;
	int iter1 = 0, iter2 = 0;

	linecpy = _strdup(line);
	add_nodeint_end(head, linecpy);
	linecpy2 = _strdup(line);
	add_nodeint_end(head, linecpy2);
	if (linecpy == NULL)
	{
		return (NULL);
	}
	argc = strtok(linecpy, DELIMITER);
	while (argc != NULL)
	{
		argc = strtok(NULL, DELIMITER);
		iter1++;
	}
	argv = malloc((iter1 + 1) * sizeof(char *));
	add_nodeint_end(head, argv);
	if (argv == NULL)
	{
		write(STDOUT_FILENO, "failed line allocation\n", 23);
		return (NULL);
	}
	writer = strtok(linecpy2, DELIMITER);
	while (writer != NULL && iter2 <= iter1)
	{
		argv[iter2] = _strdup(writer);
		add_nodeint_end(head, argv[iter2]);
		argv[iter2][_strlen(writer)] = '\0';
		writer = strtok(NULL, DELIMITER);
		iter2++;
	}

	argv[iter1] = NULL;
	return (argv);
}
