#include "holberton.h"

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument array
 *
 * Return: int
 */

int main(int argc, char **argv)
{
	int fd1, fd2, r1, w1;
	char *buf = malloc(sizeof(char) * 1024);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	if ((argv[1] == NULL) || (fd1 == -1))
	{
		close(fd1);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if ((argv[2] == NULL) || (fd2 == -1))
	{
		close(fd2);
		dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
		exit(99);
	}
	while ((r1 = read(fd1, buf, 1024)) != 0)
	{
		w1 = write(fd2, buf, r1);
		if (r1 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		if (w1 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
			exit(99);
		}
	}
	close_new(fd1);
	close_new(fd2);
	return (0);
}


/**
 * close_new - check if its closable
 * @f_n: file descrption
 *
 * Return: void
 */
void close_new(int f_n)
{
	if (close(f_n) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", f_n);
		exit(100);
	}
}