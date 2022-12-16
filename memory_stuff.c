#include "monty.h"

/**
 * _realloc - Reallocates a memory block
 * @prev: a pointer to a previous memory block.
 * @old_size: the size of the old memory block.
 * @new_size: the size of the new memory block.
 *
 * Return: a pointer to the new memory block, otherwise return NULL.
 */
void *_realloc(void *prev, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *new = NULL;
	unsigned int fill_size = old_size < new_size ? old_size : new_size;

	if (old_size == new_size)
		return (prev);
	if (prev)
	{
		if (new_size == 0)
		{
			free(prev);
			return (NULL);
		}
		new = malloc(new_size);
		if (new)
		{
			for (i = 0; i < fill_size; i++)
				*((char *)new + i) = *((char *)prev + i);
			free(prev);
			return (new);
		}
		free(prev);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		new = malloc(sizeof(char) * new_size);
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		return (new);
	}
}

/**
 * _memset - fills a section of a buffer with a constatnt byte c.
 * @buffer: the buffer that is going to be filled with the constant byte.
 * @c: the constant byte which is used to fill.
 * @length: the length of the buffer to fill.
 */
void _memset(char *buffer, int length, char c)
{
	int i;

	for (i = 0; i < length && buffer; i++)
		buffer[i] = c;
}
