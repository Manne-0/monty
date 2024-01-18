#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @head: stack head
 */
void free_stack(stack_t *head)
{
	stack_t *temp;
	temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * print_stack - prints the top of stack
 * @head: stack head
 * @line_number: line number
 */
void print_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bus.lifi = 0;
}
