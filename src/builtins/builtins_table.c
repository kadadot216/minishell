/*
** EPITECH PROJECT, 2018
** builtins_table.c
** File description:
** Builtins table related functions
*/

#include <stdlib.h>
#include "builtins/builtins.h"
#include "my.h"

builtins_cmd_t	clear_builtin(builtins_cmd_t *builtin)
{
	builtin->pcmd_idx = 0;
	builtin->pcmd = 0;
	free(builtin->cmd_name);
	builtin->cmd_fct = NULL;
	return (*builtin);
}

builtins_cmd_t	*clear_builtins(builtins_cmd_t *builtins)
{
	int	idx = 0;

	while (idx < IDX_PCMD_EOL) {
		builtins[idx] = clear_builtin(&builtins[idx]);
		idx++;
	}
	return (builtins);
}

builtins_cmd_t	map_builtin(builtins_cmd_t src)
{
	builtins_cmd_t	dest;
	dest.pcmd_idx = src.pcmd_idx;
	dest.pcmd = src.pcmd;
	dest.cmd_name = my_strdup(src.cmd_name);
	dest.cmd_fct = src.cmd_fct;
	return (dest);
}

builtins_cmd_t	*get_builtins_cmd_table(void)
{
	builtins_cmd_t *cmd_table = NULL;
	builtins_cmd_t	BUILTINS_CMD_LIST[] = {
		{IDX_CMD_SETENV, CMD_SETENV, "setenv", &ms_setenv_handle},
		{IDX_CMD_UNSETENV, CMD_UNSETENV, "unsetenv", &ms_unsetenv_handle},
		{IDX_CMD_CD, CMD_CD, "cd", &ms_cd_handle},
		{IDX_CMD_EXIT, CMD_EXIT, "exit", &ms_exit_handle},
	};
	int	idx = 0;

	cmd_table = malloc(sizeof(builtins_cmd_t) * IDX_PCMD_EOL);

	while (idx < IDX_PCMD_EOL) {
		cmd_table[idx] = map_builtin(BUILTINS_CMD_LIST[idx]);
		idx++;
	}
	return (cmd_table);
}

int	get_fct_idx_from_pcmd(builtins_cmd_t *builtins, pcmd_t pcmd)
{
	int	cur_idx = 0;

	while (cur_idx < IDX_PCMD_EOL) {
		if (pcmd == builtins[cur_idx].pcmd)
			return (builtins[cur_idx].pcmd_idx);
		cur_idx++;
	}
	return (-1);
}
