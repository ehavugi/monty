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
	/*
	char *command;
	char *number;
	int n_i;
	*/
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
		printf("couldn't allocate mem for buf\n");
	}
	if (argc == 2)
	{
		filename = argv[1];
	}

	else{
		printf("USAGE: monty file\n");
	}
	

	if (filename == NULL)
	{
		return 0;
	}



	fd = open(filename, O_RDONLY);                     
	
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		return 1;
	}
	n  = read(fd, buff, 1024);

	while(n!= 0)
	{
		n  = read(fd, buff, 1024);
		printf("\n\n|new file %s \nLine: ",filename);
		while( buff[index]!= '\0')
		{
			if (buff[index] == '\n')
			{
				printf("\nLine: ");
				line[index+1] = '\0';
				token  = strtok(line, " ");
				printf("token at %d: %s, size: %d\n",index, token, index - pre_index);
				if (strcmp(token,"push") == 0)
				{
					token = strtok(NULL," ");
					printf("parameter 2: %s, as int %d\n", token, atoi(token));
					push(head, atoi(token));
				}	
				else if (strcmp(token,"pall") == 0)
				{
					pall(head);
				}
				/*
				 * push(head,index);
				 */
				pre_index = index;
				
			}
			else
			{
				printf("%c",'\t');
				
			}
			index += 1;
			line[index-pre_index] = buff[index];
		}
	}
	pall(head);
	close(fd);
	free(buff);


	exit(EXIT_SUCCESS);
}
