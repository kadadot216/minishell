/*
** EPITECH PROJECT, 2018
** ms_env.c
** File description:
** env builtin function declaration
*/

#include "shell/shell.h"
#include "shell/env.h"
#include "my.h"

void	ms_env_handle(shell_t *shell)
{
	int	argc = my_strtablen(shell->prompt);

	if (argc == 1) {
		my_show_word_array(shell->env);
	} else {
		my_puterror("env: «");
		my_puterror(shell->prompt[1]);
		my_puterror("»: No such file or directory\n");
	}
}
