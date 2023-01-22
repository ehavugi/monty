#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * push - add an element to stack
 * @head: stack
 * @n: new element
 * Return: state of func
 */
int push(stack_t *head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (1);
	}
	else
	{
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
	}
	if (head == NULL)
	{
		head = new;
	}
	else
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = new;
		new->prev = head;
		head  =  new;
	}
	return (0);
}

/**
 * pall - print stack
 * @head: stack head
 * Return:0
 */
int pall(stack_t *head)
{
	if (head  == NULL)
	{
		return (0);
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	while (head->prev != NULL)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
	return (0);
}

/**
 * pint - print top of stack
 * @head: stack pointer
 * @line_index: line number
 * Return: exit code
 */
int pint(stack_t *head, int line_index)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_index);
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	if (head->n == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_index);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
	return (0);
}
