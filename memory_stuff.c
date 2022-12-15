#include "monty.h"
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
