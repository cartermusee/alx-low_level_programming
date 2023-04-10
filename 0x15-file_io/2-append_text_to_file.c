#include "main.h"

int _strlen(char *s);
/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: is the name of the file
 * @text_content:is the NULL terminated string to add at the end of the file
 *
 *Return:1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fds;

	ssize_t byte =0;

	ssize_t len = _strlen(text_content);

	if (filename == NULL)
	{
		return (-1);
	}
	fds = open(filename, O_WRONLY | O_APPEND);

	while (fds == -1)
	{
		return (-1);
	}
	while (len)
	{
		byte = write(fds, text_content, len);
	}
	close (fds);
	if (byte == len)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}


/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}
