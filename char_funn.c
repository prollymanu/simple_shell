#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char x)
{
	return (write(1, &x, 1));
}
/**
 * _strncpy - copie a string
 * @destt:char
 *  @srrc:char
 * @w:int
 * Return:char
 */

char *_strncpy(char *destt, char *srrc, int w)
{
int i;

i = 0;
	while (i < w && *(src + i))
	{
	*(destt + i) = *(strc + i);
	i++;
	}
	while (i < w)
	{
	*(destt + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _putss - print a string
 * @strr:pointer char
 * return:void
 */
void _putss(char *strr)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(strr[i]);
	}
_putchar('\n');
return;
}
