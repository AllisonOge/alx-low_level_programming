#include "main.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it the POXIS standard output
 * @filename: name of the file with content to be read
 * @letters: number of letters it should read and print
 *
 * Return: total number of bytes read and printed if no errors otherwise
 * 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t n, bytes_read;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

    buf = malloc(letters + 1);
	while ((bytes_read = read(fd, buf, strlen(buf))) != -1)
	{
		n = write(STDOUT_FILENO, buf, bytes_read);
		if (n == -1 || n != bytes_read)
		{
            free(buf);
			close(fd);
			return (0);
		}
	}

	if (bytes_read == -1)
	{
        free(buf);
		close(fd);
		return (0);
	}

    free(buf);
	close(fd);
	return (n);
}