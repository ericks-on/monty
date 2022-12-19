#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * _strdup - duplicates string
 * @original - original string
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *original)
{
	char *dup;
	int i = 0;
	int len;

	len = strlen(original);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
        }
	while (original[i] != '\0')
	{
		dup[i] = original[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
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
	char **cmd = malloc(sizeof(word) * 100);
	char *temp_str;

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
				temp_str = _strdup(word);
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
				n++;
				j = 0;
			}
			else
				j++;
			i++;
		}
	}
	if (word[j - 1])
	{
		word[j] = '\0';
		cmd[n] = word;
	}
	return (cmd);
}

