/*
** EPITECH PROJECT, 2018
** cmd.c
** File description:
** Command handling functions
*/

#include "my.h"
#include "builtins/builtins.h"
#include "shell/path_cmd.h"
#include "shell/prompt_type.h"

void	launch_builtin_cmd(shell_t *shell)
{
	my_putstr("This is builtin!\n");
}

void	dispatch_command(shell_t *shell)
{
	shell->pcmd = check_prompt_type(shell->prompt);
	if (shell->pcmd == CMD_PATH)
		launch_path_cmd(shell);
	if (is_a_builtin(shell->pcmd)) {
		launch_builtin_cmd(shell);
	}
	shell->pcmd = reset_prompt_type();
}
