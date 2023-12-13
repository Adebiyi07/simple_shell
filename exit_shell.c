#include "main.h"

/**
 * shell_exit - exits from the shell
 * @args: arg paremeter
 *
 * Return: 0
 */

void shell_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	tokens_f(args);
	input_f();
	exit(status);
}
