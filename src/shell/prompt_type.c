/*
** EPITECH PROJECT, 2018
** prompt_type.c
** File description:
** Prompt checking functions
*/

#include <stdlib.h>
#include "my.h"
#include "builtins/builtins.h"

int	is_a_builtin(pcmd_t pcmd)
{
	return (pcmd & (CMD_EXIT ^ CMD_SETENV ^ CMD_UNSETENV ^ CMD_CD));
}

pcmd_t	get_cmd_type(char *cmd)
{
	int		cur_idx = 0;
	builtins_cmd_t	*builtins_cmds = NULL;

	builtins_cmds = get_builtins_cmd_table();
	if (!builtins_cmds) {
		// Error msg
		return (NUL);
	}
	while (cur_idx < IDX_EOL) {
		if (my_strcmp(builtins_cmds[cur_idx].cmd_name, cmd) == 0) {
			return (builtins_cmds->pcmd);
		}
		cur_idx++;
	}
	return (CMD_EXEC);
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
