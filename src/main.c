/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"
#include "prompt.h"
#include "launch_cmd.h"
#include "builtins.h"
#include "getenv.h"

#include "shell.h"

#include "debug.h"

int	main(int ac, char **av, char **ae)
{
	shell_t	shell = init_shell();
	shell->prompt = wait_for_prompt(prompt);

	while (is_prompt_valid(shell->prompt)) {
		if (!launch_cmd(shell))
			env = launch_builtins(shell);
		shell->prompt = unset_prompt(shell->prompt);
		shell->prompt = wait_for_prompt(shell->prompt);
	}
	shell = unset_shell(shell);
	return (0);
}
