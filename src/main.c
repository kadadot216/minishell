/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include "my.h"
#include "shell/prompt.h"
#include "shell/launch_cmd.h"
#include "builtins/builtins_helpers.h"
#include "builtins/builtins_functions.h"

int	main(int ac, char **av, char **ae)
{
	shell_t	*shell = setup_shell(ae);
	shell->prompt = wait_for_prompt(shell->cwd);
	builtins_cmd_t	*builtins_cmds = NULL;

	(void)ac;
	(void)av;
	builtins_cmds = get_builtins_cmd_table();
	while (is_prompt_allocated(shell->prompt) && builtins_cmds != NULL) {
		dispatch_command(builtins_cmds, shell);
		shell->prompt = my_free_strtab(shell->prompt);
		shell->prompt = wait_for_prompt(shell->cwd);
	}
	ms_exit_handle(shell, builtins_cmds);
	return (0);
}
