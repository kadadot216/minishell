/*
** EPITECH PROJECT, 2018
** prompt_type.c
** File description:
** Prompt checking functions
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"

int	is_a_builtin(pcmd_t pcmd)
{
	return (pcmd & (CMD_EXIT ^ CMD_SETENV ^ CMD_UNSETENV ^ CMD_CD));
}

pcmd_t	get_cmd_type(char *cmd)
{
	if (my_strcmp(cmd, "exit") == 0)
		return (CMD_EXIT);
	if (my_strcmp(cmd, "setenv") == 0)
		return (CMD_SETENV);
	if (my_strcmp(cmd, "unsetenv") == 0)
		return (CMD_UNSETENV);
	if (my_strcmp(cmd, "cd") == 0)
		return (CMD_CD);
	else
		return (CMD_PATH);
}

pcmd_t	reset_prompt_type(void)
{
	return (NUL);
}

pcmd_t	check_prompt_type(char **prompt)
{
	char	*cmd = NULL;

	cmd = prompt[0];
	if (cmd[0] == '\0') {
		return (CR);
	} else {
		return (get_cmd_type(cmd));
	}
}
