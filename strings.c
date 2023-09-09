#include "shell.h"

/**
 * _strlen - returns strlen
 * @str: string
 * Return: strlen
*/
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}
/**
 * _strcmp - compares 2 strings
 * @str1: str1
 * @str2: str2
 * Return: 0 , - , +
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (str1 - str2);

		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);

	return (str1 < str2 ? -1 : 1);
}
/**
 * start_with - finds a needle in a haystack
 * @haystack: string to search
 * @needle: needle to find
 * Return: address of the next char of haystack
*/
char *start_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: destination buf
 * @src: source buf
 * Return: pointer to dest buf
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
