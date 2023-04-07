#include "main.h"


/**
 * read_textfile - function that reads a text file and prints it
 * @filename: pointer to text
 * @letters:is the number of letters it should read and print
 * Return:the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t byte;
	int fds;

	char bufer[BUFFER_SIZE * 8];

	while (!filename || !letters)
	{
		return (0);
	}
	fds = open(filename, O_RDONLY);
	if (fds == -1)
	{
		return (0);
	}
	byte = read(fds, &bufer[0], letters);
	byte = write(STDOUT_FILENO, &bufer[0], byte);
	close(fds);
	return (byte);
}
