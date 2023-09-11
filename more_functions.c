#include "shell.h"
/**
 * interact - checks if interactive
 * @info: struct address
 * Return: 1 or 0
*/
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks a delimiter
 * @c: char
 * @s: string
 * Return: 1 or 0;
*/
int is_delim(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}
/**
 * is_alpha - checks if char is alpha
 * @c: char
 * Return: 1 or 0;
*/
int is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/**
 * _atoi - converts a string to int
 * @s: string
