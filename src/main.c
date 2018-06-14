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
#include "env/getenv.h"

int	main(int ac, char **av, char **ae)
{
	shell_t	*shell = setup_shell(ae);
	shell->prompt = wait_for_prompt();

	while (is_prompt_allocated(shell->prompt) && shell->pcmd == NUL) {
		dispatch_command(shell);
		shell->prompt = my_free_strtab(shell->prompt);
		shell->prompt = wait_for_prompt();
	}
	unset_shell(shell);
	return (0);
}
