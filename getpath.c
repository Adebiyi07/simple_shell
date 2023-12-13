#include "main.h"

/**
 * get_path - returns the value of the PATH environment variable
 *
 * Return: pointer to the value of $PATH
 */
char *get_path(void)
{
	return (get_env("PATH"));
}
