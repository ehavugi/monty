#include <stdlib.h>
#include "monty.h"
/**
 * free_stack - free mem allocated to stack
 * @head: stack head
 * Return: 0
 */

int free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		head = head->next;
	}
	while (head->prev != NULL)
	{
		temp = head->prev;
		free(head);
		head = temp;
	}
	free(head);
	return (0);
}
