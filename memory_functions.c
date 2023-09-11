#include "shell.h"

/**
 * _memset = sets bytes to b
 * @s: string
 * @c: character
 * @n: n
*/
void *_memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		s[i] = c;
}
/**
 * ffree - frees
 * @pp: pointer to pointer
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
 * _realloc - reallocates memory
 * @ptr: ptr to the malloc'd block
 * @old: old size
 * @new: new size
 * Return: pointer to the allocated block
*/
void *_realloc(char *ptr, int old, int new)
{
	char *p;

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);
	p = malloc(new);

	if (!p)
		return (NULL);
	old = old < new ? old : new;

	while (old--)
		p[old] = ((char *))ptr[old];
	free(ptr);
	return (p);
}
