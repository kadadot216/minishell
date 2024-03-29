/*
** EPITECH PROJECT, 2018
** cmd.c
** File description:
** Command handling functions
*/

#include <stdlib.h>
#include "my.h"
#include "builtins/builtins_helpers.h"
#include "shell/path_cmd.h"
#include "shell/launch_cmd.h"
#include "shell/prompt_type.h"

void	launch_builtin_cmd(builtins_cmd_t *builtins, shell_t *shell)
{
	int	fct_idx = get_fct_idx_from_pcmd(builtins, shell->pcmd_f);

	if (!(fct_idx < 0) && fct_idx != IDX_CMD_EXIT) {
		builtins[fct_idx].cmd_fct(shell);
	} else if (fct_idx == IDX_CMD_EXIT) {
		builtins[fct_idx].cmd_fct(shell, builtins);
	}
}

void	dispatch_command(builtins_cmd_t *builtins, shell_t *shell)
{
	shell->pcmd_f = check_prompt_from_builtins(builtins, shell->prompt);
	if (shell->pcmd_f == CMD_EXEC)
		launch_path_cmd(shell);
	if (is_a_builtin(builtins, shell->pcmd_f)) {
		launch_builtin_cmd(builtins, shell);
	}
	shell->pcmd_f = reset_prompt_type();
}
