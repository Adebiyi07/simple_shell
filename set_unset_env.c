#include "main.h"

/**
 * setenv_s - sets value of env variable
 * @args: argument parameters
 *
 * Return: void
 */

int setenv_s(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unsetenv_s - unset env variable
 * @args: argument parameters
 *
 * Return: void
 */

int unsetenv_s(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		perror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];
	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}
