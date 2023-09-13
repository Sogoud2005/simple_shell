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
/**
 * print_err - prints errors
 * @info: return info struct
 * @estr: error string
 * Return: 0 or 1
*/
void print_err(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - prints a decimal
 * @input: input
 * @fd: file desciptor to write to
 * Return: number of characters printed
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs, current;

	if (fd == STDERR_FILENO)
		_putchar = _eputchar;

	if (input < 0)
	{
		_abs = -input;
		__putchar('-');
		count++;
	}
	else
	{
		_abs = input;
		current = _abs;
	}
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * convert_num - a clone of itoa
 * @num: number
 * @base: base
 * @flags: arguments flags
 * Return: string
*/
char *convert_num(long int num, int base, int flags)
{
	static char *array;
	static char buf[50];
	char sign = 0;
	char *ptr;
	unsigned long int n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	while (n != 0)
	{
		*--ptr = array[n % base];
		n /= base;
	}
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - replaces the first # with '\0'
 * @str: string to modify
 * Return: 0;
*/
void remove_comments(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '#' && (!i || str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
}
