#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define MAX_LINE 2048
/**
 * push - to push into stack
 * @n:number to push
 * @s: pointer to stack
 *
 * return:nothing
 */
void push(int n, stack_t *s)
{
	stack_t *new = malloc(sizeof(s));

	new -> prev = s;
	new -> next = NULL;
	new -> n = n;
	s  = new;
}
/**
 * main - executes monty
 * @argv: arguments vector
 * @argc: argument count
 *
 * Return: exit_success or exit_failure
 */
int main(int argc, char **argv)
{
	FILE *pf;
	char *buffer;
	char **cmd;
	int line = 1;
	stack_t *my_stack;
	int n;

	my_stack = malloc(sizeof(stack_t));
	if (my_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		pf = fopen(argv[1], "r");
		if (pf == NULL)
		{
			printf("Error: can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		buffer = malloc(sizeof(char) * MAX_LINE);
		if (buffer == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		while (fgets(buffer, MAX_LINE, pf) != NULL)
		{
			printf("Buffer: %s\n", buffer);
			cmd = get_cmd(buffer);
			/*=========COMMANDS======================*/
			if (strcmp(cmd[0], "push") == 0)
			{
				n = atoi(cmd[1]);
				push(n, my_stack);
			}
			else if (strcmp(cmd[0], "pall") == 0)
				pall(my_stack);
			else
			{
				printf("opcode: %s\n", cmd[0]);
				fprintf(stderr, "L%d: unknown instruction <opcode>\n",
						line);
				free(buffer);
				exit(EXIT_FAILURE);
			}
			line++;
		}
		exit(0);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
