#include "monty.h"

/**
 * pall - prints all items on the stack
 * @stack: double pointer to the end of the stack
 * @lineNum: the current line number being processed
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *items;

	if (stack == NULL)
		(void)(lineNum);

	if (!stack)
		return;

	for (items = *stack; items != NULL; items = items->next)
		printf("%d\n", items->n);
}
