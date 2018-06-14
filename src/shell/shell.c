/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include <stdlib.h>
#include "shell/shell.h"
#include "strtab.h"
#include "env/getenv.h"

int	is_shell_allocated(shell_t *shell)
{
	return (shell != NULL);
}

int	is_shell_empty(shell_t *shell)
{
	if (!is_shell_allocated(shell)) {
		// Msg error unallocated shell
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
	shell->pcmd = NUL;
	if (is_shell_empty(shell)) {
		return (NULL);
	} else {
		//Error
		return (NULL);
	}
}

shell_t	*set_empty_shell(void)
{
	shell_t		*shell = NULL;

	shell = malloc(sizeof(shell_t));
	shell->env = NULL;
	shell->paths = NULL;
	shell->prompt = NULL;
	shell->pcmd = NUL;
	return (shell);
}

shell_t	*setup_shell(char **ae)
{
	shell_t	*shell = NULL;
	char	*paths = NULL;

	shell = set_empty_shell();
	if (!is_shell_allocated(shell) || ae == NULL) {
		// Error msg
		return (NULL);
	}
	shell->env = my_strtabdup(ae);
	paths = get_env_entry(shell->env, "PATH");
	shell->paths = (paths == NULL) ? NULL : my_strtotab(paths, ":");
	shell->prompt = NULL;
	return (shell);
}
