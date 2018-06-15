/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** shell related functions
*/

#include <stdlib.h>
#include "str.h"
#include "strtab.h"
#include "shell/shell.h"
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
	shell->pcmd_f = NUL;
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
	shell->pcmd_f = NUL;
	return (shell);
}

char	**set_path_from_env(char **env)
{
	char	*path_str = NULL;
	char	**paths = NULL;

	if (env == NULL) {
		return (NULL);
	}
	path_str = get_env_entry(env, "PATH");
	paths = (path_str == NULL) ? NULL : my_strtotab(path_str, ":");
	return (paths);
}

int	path_needs_update(shell_t *shell)
{
	char	*shell_path = NULL;
	char	*paths = NULL;
	
	if (shell->env == NULL || shell->paths == NULL) {
		return (-1);
	}
	shell_path = my_strtab_to_strwtok(shell->paths, ":");
	paths = get_env_entry(shell->env, "PATH");
	return (my_strcmp(shell_path, paths) != 0);
}

shell_t	*setup_shell(char **ae)
{
	shell_t	*shell = NULL;

	shell = set_empty_shell();
	if (!is_shell_allocated(shell) || ae == NULL) {
		// Error msg
		return (NULL);
	}
	shell->prompt = NULL;
	shell->env = my_strtabdup(ae);
	shell->paths = set_path_from_env(shell->env);
	return (shell);
}
