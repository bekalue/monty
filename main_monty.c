#include "monty.h"

static stack_t *stack;
static char Data_Format;
static int Line_Count;
static int Current_Line;
static char **Lines;

/**
 * get_data_mode - Returns a pointer to the interpreter's mode flag
 *
 * Return: A pointer to the interpreter's mode flag
 */
char *get_data_mode(void)
{
	return (&Data_Format);
}

/**
 * get_lines - Retrieves the lines of the current file
 *
 * Return: The lines of the current file
 */
char **get_lines(void)
{
	return (Lines);
}


/**
 * clean_program - cleans dynamically allocated memory in a program.
 */
void clean_program(void)
{
	int b;
	stack_t *node = stack, *tmp = NULL;

	if (Lines)
	{
		for (b = 0; b < Line_Count; b++)
		{
			if (Lines[b])
				free(Lines[b]);
		}
		free(Lines);
	}
	if (node)
	{
		while (node && node->prev)
			node = node->prev;
		while (node)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}

	}
}
/**
 * main - Entry Point for Monty Bytecode Interpreter.
 *
 * @argc: number of arguments passed to the program.
 * @argv: pointer to the array of strings.
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on failure.
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Data_Format = DF_LIFO;
		Lines = file_reader(argv[1], &Line_Count);
		while (Current_Line < Line_Count)
		{
			interpret(Lines[Current_Line], Current_Line + 1, &stack);
			Current_Line++;
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	clean_program();
	exit(EXIT_SUCCESS);
}
