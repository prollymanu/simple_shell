#include "shell.h"
/**
 * for_file - Read Command From File
 * @filenamee:Filename
 * @ar:Program Name
 * Return: -1 or  0
 */

void for_file(char *filenamee, char **ar)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filenamee, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, arg);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @arg:Program Name
 * Return : Excute A line void
 */
void treat_file(char *line, int counter, FILE *fp, char **ar)
{
	char **cmdd;
	int st = 0;

	cmdd = parse_cmdd(line);

		if (_strncmp(cmdd[0], "exit", 4) == 0)
		{
			exit_bul_for_file(cmdd, line, fp);
		}
		else if (check_builtin(cmdd) == 0)
		{
			st = handle_builtin(cmdd, st);
			free(cmdd);
		}
		else
		{
			st = check_cmdd(cmdd, line, counter, ar);
			free(cmdd);
		}
}
/**
 * exitt_bul_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @cmdd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exitt_bul_for_file(char **cmdd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmdd[1] == NULL)
	{
		free(line);
		free(cmdd);
		fclose(fd);
		exit(errno);
	}
	while (cmdd[1][i])
	{
		if (_isalpha(cmdd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmdd[1]);
	free(line);
	free(cmdd);
	fclose(fd);
	exit(statue);



}
