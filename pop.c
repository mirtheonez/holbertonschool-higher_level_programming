#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The number of the line currently being run
 */
void pop(stack_t **stack, unsigned int lineNum)
{
	stack_t *elem;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	elem = *stack;

	*stack = (*stack)->next;
	free(elem);
	if (*stack)
		(*stack)->prev = NULL;
}
