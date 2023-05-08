#include "main.h"
#include <string.h>

int _strlen(char *s);
/**
 * create_file - function that creates a file
 * @filename:pointer to file
 * @text_content: pointer to a NULL terminated string to write to the file
 * Return:1 on success, -1 on failure
 */


int create_file(const char *filename, char *text_content)
{
	int fds;

	ssize_t byte = 0;
	ssize_t length = _strlen(text_content);

	while (!filename)
	{
		return (-1);
	}
	fds = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	while (fds == -1)
	{
		return (-1);
	}
	if (length)
	{
		byte = write(fds, text_content, length);
	}
	close(fds);
	return (byte == length ? 1 : -1);
}
/**
 * _strlen - function that gets the length of string
 * @s: pointer to the text whose length to check
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
