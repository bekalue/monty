#include "monty.h"

static stack_t *Values;
static char **Lines;
static int Lines_Count;
static int Current_Line;
static char Data_Format;

/**
 * main - An Entry point for Monty ByteCode interpreter
 * @argc: The number of arguments passed to the program
 * @argv: The arguments passed to the program
 *
 * Return: 0 if successful, otherwise 1
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Data_Format = DF_LIFO;
		Lines = file_reader(argv[1], &Lines_Count);
		while (Current_Line < Lines_Count)
		{
			interpret(Lines[Current_Line], Current_Line + 1, &Values);
			Current_Line++;
		}
	}
	else
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	clean_program();
	return (EXIT_SUCCESS);
}

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
 * clean_up_program - Frees dynamically allocated memory blocks
 */
void clean_program(void)
{
	stack_t *node = Values, *tmp = NULL;
	int i;

	if (Lines != NULL)
	{
		for (i = 0; i < Lines_Count; i++)
		{
			if (Lines[i] != NULL)
				free(Lines[i]);
		}
		if (Lines != NULL)
			free(Lines);
	}
	if (node != NULL)
	{
		while ((node != NULL) && (node->prev != NULL))
			node = node->prev;
		while (node != NULL)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
	}
}
