/*
** EPITECH PROJECT, 2018
** cmd.c
** File description:
** Command handling functions
*/

#include <stdlib.h>
#include "my.h"
#include "builtins/builtins.h"
#include "shell/path_cmd.h"
#include "shell/prompt_type.h"

void	launch_builtin_cmd(builtins_cmd_t *builtins, shell_t *shell)
{
	my_putstr("This is ");
	my_putstr(builtins[0].cmd_name);
}

void	dispatch_command(builtins_cmd_t *builtins, shell_t *shell)
{
	shell->pcmd_f = check_prompt_from_builtins(builtins, shell->prompt);
	if (shell->pcmd_f == CMD_EXEC)
		launch_path_cmd(shell);
	if (is_a_builtin(shell->pcmd_f)) {
		launch_builtin_cmd(builtins, shell);
	}
	shell->pcmd_f = reset_prompt_type();
}
