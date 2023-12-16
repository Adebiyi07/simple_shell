#include "main.h"

/**
 * gets_line - reads input from standard input
 *
 * Return: string inputed
*/

void *gets_line(void)
{
	static int current_position, buff_size;
	static char buffer[BUFFER_SIZE];
	char *user_input = NULL;
	char current_char;
	int input_length = 0;

	while (1)
	{
		if (current_position >= buff_size)
		{
			buff_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			current_position = 0;
			if (buff_size == 0)
				return (user_input);
			else if (buff_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}
		current_char = buffer[current_position];
		current_position++;

		if (current_char == '\n')
		{
			user_input = realloc(user_input, input_length + 1);
			user_input[input_length] = '\0';
			return (user_input);
		}
		else
		{
			user_input = realloc(user_input, input_length + 1);
			user_input[input_length] = current_char;
			input_length++;
		}
	}
}
