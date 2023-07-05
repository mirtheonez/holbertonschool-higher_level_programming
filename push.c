#include "monty.h"

/**
 * push - Pushes an item to the top of the stack
 * @num: The number to push
 */
void push(char *num)
{
	if (num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", globv.lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}
	checkNum(num);

	pushInt(atoi(num));
}

/**
 * pushInt - pushes an int to the top of the stack
 * @n: The number to be pushed
 */
void pushInt(int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = globv.stack;

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup();
		exit(EXIT_FAILURE);
	}

	new->n = n;

	if (!globv.stack)
	{
		new->next = NULL;
		new->prev = NULL;
		globv.stack = new;
	}
	else
	{
		if (globv.isStack)
		{
			new->next = globv.stack;
			new->prev = NULL;
			globv.stack->prev = new;
			globv.stack = new;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
			new->next = NULL;
		}
	}
}

/**
 * checkNum - checks if a string is a valid number
 * @num: The string to check
 */
void checkNum(char *num)
{
	int i = 0;

	if (num[0] == '-')
		i++;

	for (; num[i]; ++i)
	{
		if (!isdigit(num[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n",
					globv.lineNum);
			cleanup();
			exit(EXIT_FAILURE);
		}
	}
}
