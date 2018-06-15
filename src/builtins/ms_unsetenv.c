/*
** EPITECH PROJECT, 2018
** ms_unsetenv.c
** File description:
** unsetenv builtin function declaration
*/

#include <stdlib.h>
#include "shell/shell.h"
#include "env/getenv.h"
#include "my.h"

int	unsetenv_right_nb_args(int ac)
{
	return (ac > 1);
}

void	unsetenv_handle_exceptions(shell_t *shell)
{
	my_puterror(shell->prompt[0]);
	my_puterror(": Too few arguments.\n");
}

char	**unsetenv_remove(char **env, char *key)
{
	int	height = 0;
	char	**env_tmp = NULL;
	int	key_idx = -1;

	if (env == NULL || key == NULL) {
		return (env);
	}
	env_tmp = my_strtabdup(env);
	height = my_strtablen(env);
	key_idx = get_env_key_idx(env, key);
	if (env == NULL || key_idx < 0) {
		my_free_strtab(env_tmp);
		return (env);
	}
	env = my_strtab_realloc(env, (height - 1));
	env = my_strtabptncpy(env, env_tmp, key_idx);
	env = my_strtabcat(env, &env_tmp[key_idx + 1]);
	free(env_tmp[key_idx]);
	my_strtab_null(env_tmp, height);
	env_tmp = NULL;
	return (env);
}

shell_t	*run_ms_unsetenv(shell_t *shell, int nb_args)
{
	char	**keys = &shell->prompt[1];
	int	i = 0;

	if (keys == NULL || shell->env == NULL) {
		return (shell);
	}
	while (i < nb_args) {
		shell->env = unsetenv_remove(shell->env, keys[i]);
		i++;
	}
	return (shell);
}

void	ms_unsetenv_handle(shell_t *shell)
{
	int	ac = my_strtablen(shell->prompt);

	if (unsetenv_right_nb_args(ac) && shell->env) {
		shell = run_ms_unsetenv(shell, (ac - 1));
	} else if (shell->env) {
		unsetenv_handle_exceptions(shell);
	}
	if (path_needs_update(shell)) {
		shell->paths = set_path_from_env(shell->env);
	}
}
