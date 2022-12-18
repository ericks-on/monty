#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * get_cmd - gets monty opcode
 * @buffer: where to search for the command
 *
 * Return: the opcode in form of an array of words
 */
char **get_cmd(char *buffer)
{
	int i = 0, j = 0, n = 0;
	char *word = malloc(sizeof(char) * 15);
	char *temp_str;
	char **cmd = malloc(sizeof(word) * 100);

	if (word == NULL || cmd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (buffer[i] != '$')
	{
		if (buffer[i] == ' ')
			i++;
		else
		{
			word[j] = buffer[i];
			if (buffer[i + 1] == ' ')
			{
				j++;
				word[j] = '\0';
				temp_str = strdup(word);
				if (temp_str == NULL)
					exit(EXIT_FAILURE);
				cmd[n] = temp_str;
				free(word);
				word = malloc(sizeof(char) * 15);
				if (word == NULL)
				{
					fprintf(stderr, "Error: malloc failed\n");
					exit(EXIT_FAILURE);
				}
				printf("word after free: %s\n", cmd[n]);
				n++;
				j = 0;
			}
			else
			{
				n++;
				j++;
			}
			i++;
		}
	}
	if (word[j] != '\0')
	{
		word[j] = '\0';
		temp_str = strdup(word);
		cmd[n] = temp_str;
	}
	printf("command: %s\n", cmd[0]);
	free(word);
	return (cmd);
}

