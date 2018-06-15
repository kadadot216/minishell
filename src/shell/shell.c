/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"

int	is_shell_allocated(shell_t *shell)
{
	return (shell != NULL);
}

int	is_shell_empty(shell_t *shell)
{
	if (!is_shell_allocated(shell)) {
		return (0);
	}
	if (shell->env == NULL && shell->paths == NULL) {
		return (1);
	}
}

shell_t	*unset_shell(shell_t *shell)
{
	shell->env = my_free_strtab(shell->env);
	shell->prompt = my_free_strtab(shell->prompt);
	shell->pcmd_f = NUL;
	if (is_shell_empty(shell)) {
		return (NULL);
	}
}

shell_t	*set_empty_shell(void)
{
	shell_t	*shell = NULL;

	shell = malloc(sizeof(shell_t));
	shell->env = NULL;
	shell->paths = NULL;
	shell->prompt = NULL;
	shell->pcmd_f = NUL;
	return (shell);
}

shell_t	*setup_shell(char **ae)
{
	shell_t	*shell = NULL;

	shell = set_empty_shell();
	if (!is_shell_allocated(shell) || ae == NULL) {
		return (NULL);
	}
	shell->prompt = NULL;
	shell->env = my_strtabdup(ae);
	shell->paths = set_path_from_env(shell->env);
	return (shell);
}
