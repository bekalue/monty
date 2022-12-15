#include "monty.h"

/**
 * file_reader - Reads the lines in a file from the fd.
 * @file_path: file discriptor for the opened file.
 *
 * Return: an array of strings representing each line of the file.
 */
char **file_reader(char *file_path)
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
 * monty_interpreter - Primary function to Execute a monty bytecode script.
 * @file_path: a file name.
 *
 * Return: (EXIT_SUCCESS) on success, otherwise (EXIT_FAILURE) on failure.
 */
int monty_interpreter(char *file_path)
{
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
	int exit_status = EXIT_SUCCESS;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	exit_status = monty_interpreter(argv[1]);

	exit(EXIT_SUCCESS);

}
