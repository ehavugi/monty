#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * get_token - extract tokens
 * @line: line to consider
 * @head: stack to process
 * @line_index: line index for error printing
 * Return: 0
 */
int get_token(char *line, stack_t *head, int line_index)
{
	char *token;

	token = strtok(line, " ");
	if (token == NULL)
		return (0);
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " ");
		push(head, atoi(token));
		return (0);
	}
	else if (strcmp(token, "pall") == 0)
	{
		pall(head);
		return (0);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_index, token);
		return (EXIT_FAILURE);
	}
	return (0);
}
/**
 * process_file - process he file
 * @filename: filename
 * @head: stack
 * @buff: char buff
 * Return: 0
 */
int process_file(const char *filename, stack_t *head, char *buff)
{
	int fd;
	ssize_t n = 0;
	char *line  = malloc(BUFFER_SIZE);
	int index = 0;
	int line_index = 1;
	int line_char = 0;

	line[0] = ' ';
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	n = read(fd, buff, BUFFER_SIZE);
	while (n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		while (buff[index] != '\0' && index < BUFFER_SIZE)
		{
			if (buff[index] == '\n')
			{
				line[line_char] = '\0';
				if (get_token(line, head, line_index) == EXIT_FAILURE)
				{
					exit(EXIT_FAILURE);
				}
				line_index += 1;
				line_char = 0;
			}
			else
			{
				line[line_char] = buff[index];
				line_char += 1; }
			index += 1; }
	}
	free(line);
	return (0);
}

/**
 * main - main entry point
 * @argc: number of arguments
 * @argv: list of arguments are arrray of strings
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *filename;
	stack_t *head = malloc(sizeof(stack_t));
	char *buff = malloc(BUFFER_SIZE);

	if (head == NULL)
		return (5);
	head->n = -1;
	head->prev = NULL;
	head->next = NULL;
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		filename = argv[1];
	else
		printf("USAGE: monty file\n");
	if (filename == NULL)
		return (0);
	process_file(filename, head, buff);
	free(head);
	free(buff);
	exit(EXIT_SUCCESS);
}
