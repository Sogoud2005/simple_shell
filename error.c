#include "shell.h"

/**
 * _erratoi - converts a string into an int
 * @s: str
 * Return: 1 or 0 or -1(error)
*/
int _erratoi(char *s)
{
	int i;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s >= '0' && s <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

