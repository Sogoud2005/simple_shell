#include "shell.h"

/**
 * _strcpy - copys a string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == '\0')
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strdup - duplicates a string
 * @str: string to dup
 * Return: pointer to duplicated string
*/
char *_strdup(char *str)
{
	char *ret, *str1 = str;
	int len = 0, i = 0;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;

	ret = malloc(sizeof(char) * (len + 1));

	if (!ret)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		ret[i] = str1[i];
		*str1++;
	}
	ret[i] = 0;
	return (ret);
}
/**
 * _puts - prints a string
 * @str: string to print
*/
void _puts(char *str)
{
	int i = 0;
	
	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
