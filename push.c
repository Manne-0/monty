#include "monty.h"

/**
 * push_ - add element to the stack
 * @head: head of stack
 * @count: line number
 */
void push_(stack_t **head, unsigned int count)
{
	int n, j, flag;
	j = 0;
	flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
		n = atoi(bus.arg);

		if (bus.lifi == 0)
			add_node(head, n);
		else
			add_queue(head, n);
}
