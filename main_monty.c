#include "monty.h"

/**
 * monty_interpreter - Primary function to Execute a monty bytecode script.
 * @fd: a file descriptor to be executed.
 *
 * Return: (EXIT_SUCCESS) on success, otherwise (EXIT_FAILURE) on failure.
 */
int monty_interpreter(int fd)
{


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
	int fd;
	int exit_status;


	if(argc == 2)
	{
		if (fd = open(argv[1], O_RDONLY) == -1)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		exit_status = monty_interpret(fd);
		clean_up(fd);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	exit(exit_status);
}`
