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
 * Description: we use a fixed-size buffer of BUFFER_SIZE bytes,
 * read from the file using read() system call, which reads up to
 * BUFFER_SIZE bytes at a time from the file and stores them in buf
 * Then we check the number of bytes read against the remaining number
 * of bytes to read (letters - n) and adjust it if necessary.
 * We write the contents of buf to standard output using the write() system
 * call and increment the total number of bytes read (n) by the number of
 * bytes read. If we have read the required number of bytes (n == letters)
 * we exit the loop. Finally, we close the file with the system call close()
 * and return the total number of bytes.
 *
 * P.S. No handling of content with null characters (\0)
 *
 * Return: total number of bytes read and printed if no errors otherwise
 * 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buf[BUFFER_SIZE];
	ssize_t n = 0, bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	while (n < (ssize_t)letters && (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (n + bytes_read > (ssize_t)letters)
			bytes_read = (ssize_t)letters - n;

		bytes_written = write(STDOUT_FILENO, buf, bytes_read);
		if (bytes_written < 0 || bytes_written != bytes_read)
		{
			close(fd);
			return (0);
		}

		n += bytes_read;
	}

	if (bytes_read < 0)
	{
		close(fd);
		return (0);
	}

	close(fd);
	return (n);
}
