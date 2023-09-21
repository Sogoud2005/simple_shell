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
/**
 * list_to_strings - an array of strings in list->str
 * @head: pointer to node
 * Return: pointer to strings
*/
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));

	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(sizeof(char) * (_strlen(node->str) + 1));

		if (!str)
		{
			for (j = 0; j < i; j++)
			{
				free(strs[j])
			}
			free(strs);
			return (NULL);
		}

		str = _strcopy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
/**
 * node_starts_with - finds A node
 * @node: node pointer
 * @prefix: search
 * @c: char
 * Return: node or NULL
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_at_index - finds a node at a certain index
 * @head: head
 * @node: node
 * Return: index of node or -1
*/
ssize_t get_node_at_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
