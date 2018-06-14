/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include <stdlib.h>
#include "shell.h"
#include "strtab.h"

int	is_shell_allocated(shell_t shell)
{
	return (shell != NULL);
}

int	is_shell_empty(shell_t shell)
{
	if (!is_shell_allocated(shell)) {
		// Msg error unallocated shell
		return (0);
	}
	if (shell->env == NULL && shell->paths == NULL) {
		return (1);
	}
}

shell	unset_shell(shell_t shell)
{
	shell->env = my_free_strtab(shell->env);
	shell->prompt = unset_prompt(shell->prompt);
	if (is_shell_empty(shell)) {
		return (NULL);
	} else {
		//Error
		return (NULL);
	}
}

shell_t	set_empty_shell(void)
{
	shell_t		shell = NULL;

	shell = malloc(sizeof(shell_t));
	shell->env = NULL;
	shell->paths = NULL;
	shell->prompt = NULL;
	return (shell);
}

shell_t	setup_shell(char **ae)
{
	shell_t	shell = NULL;

	shell = set_empty_shell();
	if (!is_shell_allocated(shell)) {
		// Error msg
		return (NULL);
	}
	shell->env = my_strtabdup(ae);
	shell->paths = my_strtotab(get_env_entry(shell->env, "PATH"), ":");
	shell->prompt = set_empty_prompt();
	return (shell);
}
