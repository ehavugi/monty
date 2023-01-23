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

/**
 * swap - swap
 * @head: stack pointer
 * @line_index: index of line
 * Return: 0
 */
int swap(stack_t *head, int line_index)
{
	stack_t *temp;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_index);
		return (EXIT_FAILURE);
	}
	if (head->prev != NULL)
	{
		if ((head->prev)->prev != NULL)
		{
			temp = head->prev;
			temp->next = NULL;
			temp->prev = head;
			head = head->prev;
			head->next = temp;
		}
	}
	return (0);
}

/**
 * add - add
 * @head: head
 * @line: line index
 * Return:0
 */
int add(stack_t *head, int line)
{
	stack_t *temp;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		return (EXIT_FAILURE);
	}
	if (head->prev !=  NULL)
	{
		if (head->prev->prev != NULL)
		{
			temp = head->prev;
			temp->n = (head->prev)->n + head->n;
			temp->prev = head->prev->prev;
			temp->next = NULL;
			head = temp;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
