#include "monty.h"
/**
 * _strcat - Concatinates two strings.
 * @left: the left string.
 * @right: the rigth string.
 *
 * Return: a pointer to concatinated string.
 *
 */
char *_strcat(char *left, char *right)
{
	int i;
	char *str;
	int left_length = str_len(left);
	int right_length = str_len(right);

	str = _realloc(str, 0,sizeof(char) * (left_length + right_length + 1));
	if (!str)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; left && left[i] != '\0'; i++)
		str[i] = left[i];
	for (i = 0; right && right[i] != '\0'; i++)
		str[left_length + i] = right[i];
	str[left_lenth + i] = '\0';
	return (str);
}
