#include "shell.h"
/**
 * check_delimm - Checks If A Character Match Any Char *
 * @x: Character To Check
 * @strr: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int check_delimm(char x, const char *strr)
{
	unsigned int t;

	for (t = 0; str[t] != '\0'; t++)
	{
		if (x == str[t])
			return (1);
	}
	return (0);
}

/**
 * _strtokk - Token A String Into Token (strtrok)
 * @strr: String
 * @delimm: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtokk(char *strr, const char *delimm)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = strr;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delimm(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delimm(nt[i], delimm) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
