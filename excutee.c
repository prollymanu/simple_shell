#include "shell.h"

/**
 * handle_builtinn - Handle Builtin Command
 * @cmdd: Parsed Command
 * @err:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handle_builtinn(char **cmd, int err)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmdd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmdd, err));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmdd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmdd:Parsed Command
 * @inputt: User Input
 * @t:Shell Excution Time Case of Command Not Found
 * @ar:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmdd(char **cmdd, char *inputt, int t, char **ar)
{
	int status;
	pid_t pid;

	if (*cmdd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmdd, "./", 2) != 0 && _strncmp(*cmdd, "/", 1) != 0)
		{
			path_cmdd(cmdd);
		}

		if (execve(*cmdd, cmdd, environ) == -1)
		{
			print_error(cmd[0], t, ar);
			free(inputt);
			free(cmdd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
