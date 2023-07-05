#include "monty.h"

globv_t globv;

/**
 * main - Main function the program enters in
 * @argc: The number of arguments passed to the program
 * @argv: Pointer to array of pointers each pointing to an argument passed to
 * the program
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	globv.stack = NULL;
	globv.line = NULL;
	globv.isStack = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	process();
	cleanup();
	return (0);
}

/**
 * openfile - Opens the monty file passed by the user
 * @name: The name of the file
 */
void openfile(char *name)
{
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	globv.file = file;
}

/**
 * process - processes the monty file line by line
 */
void process(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;

	while ((read = getline(&globv.line, &len, globv.file)) != -1)
	{
		globv.lineNum++;

		opcode = strtok(globv.line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			runopcode(opcode, globv.lineNum);
	}
}

/**
 * runopcode - Runs a given opcode, unless it is invalid
 * @opcode: The opcode to run
 * @lineNum: The line number the opcode is on
 */
void runopcode(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&globv.stack, lineNum);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, opcode);
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * cleanup - Function to clean up stack and file
 */
void cleanup(void)
{
	stack_t *item;

	while (globv.stack)
	{
		item = globv.stack->next;
		free(globv.stack);
		globv.stack = item;
	}

	free(globv.line);

	fclose(globv.file);
}
