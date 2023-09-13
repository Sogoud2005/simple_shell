#include "shell.h"

/**
 * list_len - prints the length of the list
 * @h: the list
 * Return: the length of the list
*/
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}

