#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include <unistd.h>

/**
 * read_textfile - read text file
 * @filename: the file name
 * @letters: letters to read
 *
 * Return: number of characters read/print on stdout
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf = malloc(letters);
	ssize_t n = 0;
	ssize_t n2 = 0;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

	n = read(fd, buf, letters);
	n2 = write(1, buf, n);
	if (n2 != n)
	{
		return (0);
	}
	/*exit or close */
	free(buf);
	close(fd);

	return (n);
}
