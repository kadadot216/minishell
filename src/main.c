/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/prompt.h"
#include "shell/launch_cmd.h"
#include "builtins/builtins.h"
#include "shell/env.h"

int	main(int ac, char **av, char **ae)
{
	shell_t	*shell = setup_shell(ae);
	shell->prompt = wait_for_prompt();
	builtins_cmd_t	*builtins_cmds = NULL;

	builtins_cmds = get_builtins_cmd_table();
	while (is_prompt_allocated(shell->prompt) && builtins_cmds != NULL) {
		dispatch_command(builtins_cmds, shell);
		shell->prompt = my_free_strtab(shell->prompt);
		shell->prompt = wait_for_prompt();
	}
	builtins_cmds = clear_builtins(builtins_cmds);
	unset_shell(shell);
	return (0);
}
