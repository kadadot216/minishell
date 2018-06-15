/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** Shell's path related functions
*/

#include <stdlib.h>
#include "str.h"
#include "strtab.h"
#include "shell/shell.h"
#include "shell/env.h"

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

