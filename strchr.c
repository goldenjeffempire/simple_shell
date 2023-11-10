#include "joshell.h"

/**
 * *_strchr - locates a character in a string
 * @s: string to search
 * @e: char to find
 *
 * Return: a pointer to the first occurrence of the character
 * e in the string s, or NULL if the character is not found
 */

char *_strchr(char *s, char e)
{
		int b;

		while (1)
		{
			b = *s++;
			if (b == e)
			{
				return (s - 1);
			}
			if (b == '\0')
			{
				return (NULL);
			}
		}
}
