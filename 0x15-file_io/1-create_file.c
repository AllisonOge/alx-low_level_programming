#include "main.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - creates a file with permission rw------- or 0600
 * truncated if not exist
 * @filename: name of the file to be created
 * @text_content: a NULL terminated string to write to the file
 *
 * Description: We use the O_WRONLY, O_CREAT and O_TRUNC flags to open the file
 * in write-only mode, create if it doesn't exist, and truncate it to zero if
 * it does exist. We also set permission to read and write for the owner 0600
 * or S_IRUSR | S_IWUSR flags. The write() system call writes the contents
 * of text_content to the file.
 * If text_content is NULL we don't write anything to the file.
 *
 * Return: 1 if successful otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);
	if (text_content != NULL)
	{
		ssize_t n = write(fd, text_content, strlen(text_content));

		if (n < 0)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
