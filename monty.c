#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
	char *filename = NULL;
	int fd;
	char *buff  = malloc(1024);
	ssize_t n = 0;

	if (argc == 2)
	{
		filename = argv[1];
		printf("file is %s\n", filename);
		
	}
	else{
		printf("%d \n", argc);
	}

	if (filename == NULL)
	{
		return 0;
	}

	fd = open(filename, O_RDONLY);

	if (fd = -1)
	{
		printf("couldn't open\n");
		return 0;
	}
	n = 10000;
	printf("yay\n");
	while (n >= 1024)
	{
		n = read(fd,buff, 1024);
		write(1, buff, n);
		free(buff);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
