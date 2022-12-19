#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * pall - prints all in stack
 * @s: pointer to the stack
 *
 */
void pall(stack_t *s)
{
	stack_t *temp;

	temp = s;
	printf("%d\n", temp -> n);
	while (temp -> prev != NULL)
	{
		printf("%d\n", temp -> n);
		temp = temp -> prev;
	}
	if (temp -> n)
	{
		printf("%d\n", temp -> n);
	}
}
