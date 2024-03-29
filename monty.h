#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
void free_stack(stack_t *head);
void print_stack(stack_t **head, unsigned int line_number);
void add_queue(stack_t **head, int n);
void print_queue(stack_t **head, unsigned int line_number);
void add_node(stack_t **head, int n);
void push_(stack_t **head, unsigned int count);
void pall_(stack_t **head, unsigned int line_number);
void pint_(stack_t **head, unsigned int line_number);
void pop_(stack_t **head, unsigned int line_number);
void swap_(stack_t **head, unsigned int line_number);
void add_(stack_t **head, unsigned int line_number);
void nop_(stack_t **head, unsigned int line_number);
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);
#endif
