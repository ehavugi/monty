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
	stack_t *temp  = head;

	if (temp  == NULL)
	{
		return (1);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
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
		return (EXIT_FAILURE);
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	if (head->prev == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_index);
		return (EXIT_FAILURE);
	}
	printf("%d\n", head->n);
	return (0);
}
