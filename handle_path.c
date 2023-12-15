#include "main.h"

/**
 * get_env - gets the path
 *
 * @path_name: pointer to data struct
 *
 * Return: void
 */

char *get_env(char *path_name)
{
	char **environ_cursor, *env_pointer;
	char *name_pointer;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_pointer = *environ_cursor;
		name_pointer = path_name;
		while (*env_pointer == *name_pointer)
		{
			if (*env_pointer == '=')
				break;
			env_pointer++;
			name_pointer++;
		}
		if ((*env_pointer == '=') && (*name_pointer == '\0'))
			return (env_pointer + 1);
		environ_cursor++;
	}
	return (NULL);
}
