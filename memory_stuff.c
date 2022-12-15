#include "monty.h"

/**
 * _realloc - Reallocates a memory block
 * @prev: a pointer to a previous memory block.
 * @old_size: the size of the old memory block.
 * @new_size: the size of the new memory block.
 *
 * Return: a pointer to the new memory block, otherwise return NULL.
 */
void *_realloc(void *prev, size_t old_size, size_t new_size)
{

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
