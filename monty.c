#include <stdio.h>
#include <stdlib.h>
#include "monty.c"
/**
 * push - pushes an element to the stack
 * @stack
 * @line_number: line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (!stack || !line_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	int value = atoi(global_opcode_argument);

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - prints all the values on the satck
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	
	while(*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
	}
	fclose(file);
	if (line)
		free(line);
	return EXIT_SUCCESS;
}

