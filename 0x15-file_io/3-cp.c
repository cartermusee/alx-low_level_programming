#include "main.h"
/**
 * main - copies file1 contents into another file2
 * @argc: argument 
 * @argv: pointer to arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
        int file_to, file_from, dr;

        if (argc != 3)
        {
                dprintf(STDERR_FILENO, "Usage: copying file_from file_to\n");
                exit(97);
        }
        file_from= open(argv[1], O_RDONLY);
        if (file_from == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
                exit(98);
        }
        file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	        while ((dr = read(file_from, buffer, BUFFER_SIZE)) > 0)
        {
                if (file_to == -1 || write(file_to, buffer, dr) == -1)
                {
                        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
                        close(file_from);
                        exit(99);
                }
        }
        if (dr == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
                exit(98);
        }
        if (close(file_from) == -1 || close(file_to) == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
                exit(100);
        }
        return (0);
}
