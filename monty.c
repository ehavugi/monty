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
 * numeric - check if number is numeric
 * @str: string to check
 * Return: -1 if not numeric and positve number if num
 */
int numeric(char *str)
{
	int index = 0;
	int len = 0;

	if (str == NULL)
	{
		return (-1);
	}
	len = strlen(str);
	while (index < len)
	{
		if ((str[index] >= '0' && str[index] <= '9') || str[index] == '-')
		{
			index += 1;
		}
		else
		{
			printf("%s  , %c", str, str[index]);
			return (-1);
		}
	}
	return (index);
}

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
	int exit_code = EXIT_SUCCESS;

	token = strtok(line, " ");
	if (token == NULL)
		return (exit_code);
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " ");
		if (token == NULL || numeric(token) < 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_index);
			return (EXIT_FAILURE);
		}
		exit_code = push(head, atoi(token));
		return (exit_code);
	}
	else if (strcmp(token, "pint") == 0)
	{
		pint(head, line_index);
	}
	else if (strcmp(token, "pall") == 0)
	{
		exit_code = pall(head); }
	else if (strcmp(token, "nop") == 0)
	{
		exit_code = 0; }
	else if (strcmp(token, "add") == 0)
	{
		exit_code = add(head, line_index); }
	else if (strcmp(token, "swap") == 0)
	{
		exit_code = swap(head, line_index); }
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_index, token);
		return (EXIT_FAILURE);
	}
	return (exit_code);
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
	int offset = 0;
	ssize_t n;
	char *line;
	int index = 0;
	int line_index = 1;
	int line_char = 0;
	int last_index = 0;

	line  = malloc(BUFFER_SIZE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE); }
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		while (buff[index] != '\0' && index < BUFFER_SIZE)
		{
			if (buff[index] == '\n')
			{
				line[line_char] = '\0';
				if (get_token(line, head, line_index) == EXIT_FAILURE)
				{
					return (EXIT_FAILURE); }
				line_index += 1;
				line_char = 0;
				last_index = index; }
			else
			{
				line[line_char] = buff[index];
				line_char += 1; }
			index += 1; }
		offset += last_index;
		lseek(fd, offset, SEEK_SET); }
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

/**
 * main - main entry point
 * @argc: number of arguments
 * @argv: list of arguments are arrray of strings
 * Return: 0
 */
int main(int argc, char *argv[])
{

	stack_t *head = malloc(sizeof(stack_t));
	char *buff = malloc(BUFFER_SIZE);
	int exit_code = EXIT_SUCCESS;

	/*
	 * instruction_t instructions[10];
	 * instructions = {
		{'push',push},
		{'pall',pall},
		{'pint',pint},
		{NULL, NULL}
		*/
	if (buff == NULL || head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		free(buff);
		exit(EXIT_FAILURE);
	}
	head->n = -1; /* to find a robust way to initialize a stack*/
	head->prev = NULL;
	head->next = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack(head);
		free(buff);
		exit(EXIT_FAILURE);
	}

	exit_code = process_file(argv[1], head, buff);
	free(buff);
	free_stack(head);
	exit(exit_code);
}
