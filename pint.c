#include "monty.h"

/**
 * pint - prints the int at the top of the stack
 * @stack: double pointer to the head of the stack
 * @lineNum: the number of the current line being processed
 */

void pint(stack_t **stack, unsigned int lineNum)

{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
