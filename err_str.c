#include "shell.h"
/**
 * _eputs - prints a string
 * @str: string to print
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putfd - write char c to given fd
 * @c: char to write
 * @fd: file descriptor
 * Return: 1 0r -1
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}
/**
 * _putsfd - write input str to given fd
 * @str: str to write
 * @fd: file desciptor
 * Return: number of chars put
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
