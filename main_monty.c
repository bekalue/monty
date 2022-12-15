#include "monty.h"

static stack_t *stack;
static int Line_Count;
static int Current_Line;
static char **Lines;

/**
 * file_reader - Reads the lines in a file from the fd.
 * @file_path: file discriptor for the opened file.
 *
 * Return: an array of strings representing each line of the file.
 */
char **file_reader(char *file_path, int *Line_Count)
{
	char *buffer, *str;
	bool stop_reading = FALSE;
	struct stat file_status;
	size_t read = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	fd = open(file_path, O_RDONLY);
	stat(file_path, &file_status);
	if ((fd >= 0) && S_ISREG(file_status.st_mode))
	{
		while (!stop_reading)
		{
			_memset(buffer, BUFSIZE - 1, '\0');
			read = read(fd, (void *)buffer, BUFSIZE - 1);
			if ((n <= 0) || (n < 1024 - 1))
				stop_reading = TRUE;
			buffer[read] = '\0';
			str = _strcat(str, buffer);
		}
		close(fd);
		free(buffer);
		return (str_split(str, '\n'));
	}
	else
	{
		if (fd >= 0)
			close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", path_name);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (NULL);
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
		for (b = 0; b < Lines_Count; b++)
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
		Lines = file_reader(argv[1], &Line_Count);
		while (Current_Line < Lines_Count)
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
