#include "monty.h"

/**
 * file_reader - Reads the lines in a file from the fd.
 * @file_path: file discriptor for the opened file.
 * @Line_Count: line count of the file.
 *
 * Return: an array of strings representing each line of the file.
 */
char **file_reader(char *file_path, int *Line_Count)
{
    char *buffer, *str = NULL;
    bool stop_reading = FALSE;
    struct stat file_status;
    int rd = 0, fd;

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
            rd = read(fd, (void *)buffer, BUFSIZE - 1);
            if ((rd <= 0) || (rd < BUFSIZE - 1))
                stop_reading = TRUE;
            buffer[rd] = '\0';
            str = _strcat(str, buffer);
        }
        close(fd);
        free(buffer);
        return (str_split(str, '\n', Line_Count));
    }
    else
    {
        if (fd >= 0)
            close(fd);
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        free(buffer);
        clean_program();
        exit(EXIT_FAILURE);
    }
    return (NULL);
}
/**
 * read_command - Reads a specific command for the given string.
 * @str: the string to read from.
 * @offset: the offset into the string.
 *
 * Return: The opicode command, otherwise NULL.
 */
char *read_command(char *str, int *offset)
{
    int i = 0, a = -1, len;
    char *command = NULL;

    for (i = 0; str && str[i + *offset] != '\0'; i++)
    {
        a = !is_whitespace(str[i + *offset]) && (a == -1) ? i : a;
        if ((a != -1) && is_whitespace(str[i + *offset]))
            break;
    }
    len = a > -1 ? i - a : 0;
    if (len > 0)
    {
        command = _realloc(command, 0, sizeof(char) * (len + 1));
        for (i = 0; i < len; i++, a++)
            command[i] = str[a + *offset];
        command[i] = '\0';
    }
    *offset = len > 0 ? a : i + *offset;

    return (command);
}