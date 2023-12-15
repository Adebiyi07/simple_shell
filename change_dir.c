#include "main.h"

/**
 * change_dir - changes the pwd  of the shell
 *
 * @args: array of args
 */

void change_dir(char **args)
{
	int new_pwd;
	char *dir = args[1];

	if (dir == NULL)
	{
		dir = get_env("HOME");
		if (dir == NULL)
		{
			puts("cd: No HOME directory found\n");
			return;
		}
	}

	new_pwd = chdir(dir);
	if (new_pwd == -1)
	{
		perror("cd");
	}
}
