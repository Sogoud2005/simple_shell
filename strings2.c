#include "shell.h"

/**
 * _strncpy - copies string up to n bytes
 * @dest: dest
 * @src: source
 * @n: bytes
 * Return: pointer to string created
*/
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
/**
 * _strncat - cat up to n bytes
 * @dest: dest
 * @src: source
 * @n: bytes
 * Return: pointer to string dest
*/
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
/**
 * _strchr - find a char in str
 * @str: string to search
 * @c: char to find
 * Return: NULL or *
*/
char *_strchr(char *str, char c)
{
	if (!str)
		return (NULL);

	while (*str++ != '\0')
	{
		if (*str == c)
			return (str);
	}
	return (NULL);
}
