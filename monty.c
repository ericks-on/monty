#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define MAX_LINE 2048
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
	int cmd_i = 0;
	int line = 1;

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
			printf("first command: %s\n", cmd[0]);
			while (cmd[cmd_i] != NULL)
				cmd_i++;
			if (strcmp(cmd[0], "push") == 0)
			{
				if (cmd_i != 2 || !atoi(cmd[1]))
				{
					fprintf(stderr, "L%d: unknown instruction <opcode>\n", line);
					exit(EXIT_FAILURE);
				}
				printf("ready to push\n");
			}
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
