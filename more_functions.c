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
 * Return: converted int or 0
*/
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
	{
		output = -res;
	}
	else
		output = res;
	return (output);
}
