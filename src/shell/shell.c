/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include <stdlib.h>
#include "my.h"
#include "builtins/cd.h"
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
	if (!shell->env && !shell->paths && !shell->cwd && !shell->homedir) {
		return (1);
	}
}

shell_t	*unset_shell(shell_t *shell)
{
	shell->env = my_free_strtab(shell->env);
	shell->prompt = my_free_strtab(shell->prompt);
	free(shell->homedir);
	free(shell->cwd);
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
	shell->homedir = NULL;
	shell->cwd = NULL;
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
	shell->homedir = my_strdup(get_env_entry(ae, "HOME"));
	shell->cwd = ms_cd_get_cd();
	shell->env = my_strtabdup(ae);
	shell->paths = set_path_from_env(shell->env);
	return (shell);
}
