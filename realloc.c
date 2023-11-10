#include "joshell.h"

/**
 * *_realloc - reallocates a memory block using malloc and jfree
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *j, *oj;
	unsigned int h = 0;

	if (old_size == new_size)
		return (ptr);
	if (ptr && new_size == 0)
	{
		jfree(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));

	j = malloc(new_size);
	if (j == NULL)
		return (NULL);
	oj = ptr;

	if (new_size < old_size)
	{
		while (h < new_size)
		{
			j[h] = oj[h];
			h++;
		}
	}
	if (old_size < new_size)
	{
		h = 0;
		while (h < old_size)
		{
			j[h] = oj[h];
			h++;
		}
	}
	jfree(ptr);
	return (j);
}
