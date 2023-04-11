#include "main.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the filename to append contents
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd < 0)
		return (-1);

	n = write(fd, text_content, strlen(text_content));
	if (n < 0)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (n);
}
