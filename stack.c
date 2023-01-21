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
		printf("new stack\n");
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
