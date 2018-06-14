/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include "shell.h"
#include <stdlib.h>

int	is_shell_invalid(shell_t shell)
{
	return (shell == NULL);
}

int	is_shell_empty(shell_t shell)
{
	if (is_shell_invalid(shell)) {
		// Msg error invalid shell
		return (0);
	}
	if (shell->env == NULL && shell->paths == NULL) {
		return (1);
	}
}

shell_t	init_shell(void)
{
	shell_t		shell = NULL;

	shell = malloc(sizeof(shell_t));
	shell->env = NULL;
	shell->paths = NULL;
	shell->prompt = NULL;
	return (shell);
}
