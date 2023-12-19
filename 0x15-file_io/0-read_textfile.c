#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 *
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten;
	char buf[BUFSIZ];

	if (filename == NULL)
		return 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return 0;

	while ((nread = read(fd, buf, BUFSIZ)) > 0)
	{
		if (letters > 0 && nread > letters)
			nread = letters;

		nwritten = write(STDOUT_FILENO, buf, nread);
		if (nwritten != nread)
		{
			close(fd);
			return 0;
		}

		letters -= nread;
		if (letters == 0)
			break;
	}

	close(fd);

	if (nread == -1)
		return 0;

	return nread;
}

