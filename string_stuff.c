#include "monty.h"

/**
 * str_len - Computes the length of the string.
 * @str: the string.
 *
 * Return: the length of the string.
 */
int str_len(const char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * str_split - Splits a string into smaller strings at a given character.
 * @str: the string to split.
 * @c: the character at which split is to be performed.
 * @len_out: The pointer which would contain the number of smaller strings
 * Return: a pointer to array of strings.
 */
char **str_split(char *str, char c, int *len_out)
{
	char **sstr = NULL;
	int i, o, j = 0, n = 0, s = 0;

	if (!str)
		return (sstr);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == c || (str[i] != c && str[i + 1] == '\0'))
		{
			sstr = _realloc(sstr, sizeof(void *) * n, sizeof(void *) * (n + 1));
			s = str[i] == c ? i - j : i - j + 1;
			sstr[n] = NULL;
			sstr[n] = _realloc(sstr[n], 0, sizeof(char) * (s + 1));
			for (o = 0; o < s; o++)
				sstr[n][o] = str[j + o];
			sstr[n][o] = '\0';
			j = i + 1;
			n++;
		}
	}
	if (len_out != NULL)
		*len_out = n;
	return (sstr);
}

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
	char *str = NULL;
	int left_length = str_len(left);
	int right_length = str_len(right);

	str = _realloc(str, 0, sizeof(char) * (left_length + right_length + 1));
	if (!str)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; left && left[i] != '\0'; i++)
		str[i] = left[i];
	for (i = 0; right && right[i] != '\0'; i++)
		str[left_length + i] = right[i];
	str[left_length + i] = '\0';

	return (str);
}
