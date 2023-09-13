#include "shell.h"

/**
 * *add_node_end - adds a node at the end
 * @head: the head
 * @str: the string to add
 * Return: a pointer
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = (list_t *)malloc(sizeof(list_t));
	list_t *temp = *head;

	if (new == NULL || str == NULL)
		return (NULL);

	new->str = (char *)str;
	new->len = _strlen((char *)str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;

	return (new);
}
/**
 * *add_node - adds a node at the start of a list
 * @head: the new head
 * @str: input string
 * Return: the address of the new element, or NULL if it failed
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp = (list_t *)malloc(sizeof(list_t));

	if (temp == NULL || str == NULL)
		return (NULL);

	temp->str = (char *)str;
	temp->len = _strlen((char *)str);
	temp->next = *head;
	*head = temp;

	return (*head);
}
/**
 * print_list - prints a list of elements
 * @h: list to print
 * Return: no. of nodes
*/
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * delete_nodeint_at_index - deletes a node
 * @head: head pointer
 * @index: index
 * Return: 1 or -1
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	temp = *head;

	while (temp)
	{
		if (i == index)
		{
			prev->next = temp->next;
			free(temp);
			return (1);
		}
		i++;
		prev = temp;
		temp = temp->next;
	}
	return (-1);
}
/**
 * free_list - frees a list
 * @head: the head list
 * Return: none
*/
void free_list(list_t *head)
{
	list_t *free_nodes;

	while (head)
	{
		free_nodes = head->next;
		free(head->str);
		free(head);
		head = free_nodes;
	}
}
