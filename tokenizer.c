#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int j, k, l, n, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (j = 0; str[j] != '\0'; j++)
		if (!is_delim(str[j], d) && (is_delim(str[j + 1], d) || !str[j + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (is_delim(str[j], d))
			j++;
		l = 0;
		while (!is_delim(str[j + l], d) && str[j + l])
			l++;
		s[k] = malloc((l + 1) * sizeof(char));
		if (!t[k])
		{
			for (l = 0; l < k; l++)
				free(t[l]);
			free(t);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			t[k][n] = str[j++];
		t[k][n] = 0;
	}
	t[k] = NULL;
	return (t);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int j, k, l, n, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		if ((str[j] != d && str[j + 1] == d) ||
		    (str[j] != d && !str[j + 1]) || str[j + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (str[j] == d && str[j] != d)
			j++;
		l = 0;
		while (str[j + l] != d && str[j + l] && str[j + l] != d)
			l++;
		t[k] = malloc((l + 1) * sizeof(char));
		if (!t[k])
		{
			for (l = 0; l < k; l++)
				free(t[l]);
			free(t);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			t[k][n] = str[j++];
		t[k][n] = 0;
	}
	t[k] = NULL;
	return (t);
}
