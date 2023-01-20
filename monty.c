#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <sys/types.h>                                         
#include <sys/stat.h>                                          
#include <fcntl.h>
#include <unistd.h> 
#include <string.h>

int main(int argc, char *argv[])
{
	
	const char *filename;
	int fd; 
	char *buff = malloc(1024);
	ssize_t n = 0;
	char *line = malloc(1024);
	int index  = 0;
	int pre_index = 0;
	char *token;
	stack_t *head  = malloc(sizeof(stack_t));

	line[0] = ' ';
	if (head == NULL)
	{
		return 5;
	}
	head->n = -1;
	head->prev = NULL;
	head->next = NULL;
	if (buff == NULL)
	{
		printf("couldn't allocate mem for buf\n"); }
	if (argc == 2)
	{
		filename = argv[1]; }
	else{
		printf("USAGE: monty file\n"); }
	if (filename == NULL)
	{
		return 0; }
	fd = open(filename, O_RDONLY);                     
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		return 1; }
	n  = read(fd, buff, 1024);
	while(n!= 0)
	{
		n  = read(fd, buff, 1024);
		while( buff[index]!= '\0')
		{
			if (buff[index] == '\n')
			{
				line[index+1] = '\0';
				token  = strtok(line, " ");
				if (strcmp(token,"push") == 0)
				{
					token = strtok(NULL," ");
					push(head, atoi(token));
				}	
				else if (strcmp(token,"pall") == 0)
				{
					pall(head);
				}
				pre_index = index;
			}
			index+=1;
			line[index-pre_index] = buff[index];
		}
	}
	close(fd);
	free(buff);
	free(line);
	exit(EXIT_SUCCESS);
}
