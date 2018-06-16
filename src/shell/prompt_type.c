/*
** EPITECH PROJECT, 2018
** prompt_type.c
** File description:
** Prompt checking functions
*/

#include <stdlib.h>
#include "my.h"
#include "builtins/builtin_types.h"

int	is_a_builtin(builtins_cmd_t *builtins, pcmd_t pcmd)
{
	int	idx = 0;

	while (idx < IDX_PCMD_EOL) {
		if (pcmd == builtins[idx].pcmd) {
			return (1);
		}
		idx++;
	}
	return (0);
}

pcmd_t	get_cmd_type(builtins_cmd_t *builtins, char *cmd)
{
	int	cur_idx = 0;

	if (!builtins) {
		return (NUL);
	}
	while (cur_idx < IDX_PCMD_EOL) {
		if (my_strcmp(builtins[cur_idx].cmd_name, cmd) == 0) {
			return (builtins[cur_idx].pcmd);
		}
		cur_idx++;
	}
	return (CMD_EXEC);
}

pcmd_t	reset_prompt_type(void)
{
	return (NUL);
}

pcmd_t	check_prompt_from_builtins(builtins_cmd_t *builtins, char **prompt)
{
	char	*cmd = NULL;

	cmd = prompt[0];
	if (cmd[0] == '\0') {
		return (CR);
	} else {
		return (get_cmd_type(builtins, cmd));
	}
}
