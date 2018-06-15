/*
** EPITECH PROJECT, 2018
** ms_setenv.c
** File description:
** setenv builtin function declaration
*/

#include <stdlib.h>
#include "shell/shell.h"
#include "builtins/builtins_functions.h"
#include "shell/path_cmd.h"
#include "env/getenv.h"
#include "my.h"

char	*create_env_entry(char *key, char *value)
{
	char	*env_entry = NULL;
	int	env_entry_length = 0;

	if (key == NULL) {
		return (key);
	}
	env_entry_length = (my_strlen(key) + my_strlen(value) + 1);
	env_entry = malloc(env_entry_length + 1);
	if (env_entry == NULL) {
		return (NULL);
	}
	my_memset(env_entry, '\0', env_entry_length);
	env_entry = my_strcat(env_entry, key);
	env_entry = my_strcat(env_entry, "=");
	env_entry = my_strcat(env_entry, value);
	return (env_entry);
}

char	**setenv_append(char **env, char *key, char *value)
{
	int	height = 0;
	char	*env_entry = NULL;
	char	**env_tmp = NULL;

	if (env == NULL || key == NULL) {
		return (env);
	}
	env_entry = create_env_entry(key, value);
	env_tmp = my_strtabdup(env);
	height = my_strtablen(env);
	env = my_strtab_realloc(env, (height + 1));
	if (env == NULL || env_tmp == NULL) {
		return (env);
	}
	env = my_strtabptncpy(env, env_tmp, height);
	my_strtab_null(env_tmp, height);
	env_tmp = NULL;
	env[height] = env_entry;
	return (env);
}

char	**setenv_replace(char **env, char *key, char *new_value, int key_idx)
{
	char	*new_entry = NULL;	
	int	ne_length = 0;

	if (env == NULL || key == NULL) {
		return (env);
	}
	ne_length = (my_strlen(key) + my_strlen(new_value) + 1);
	new_entry = malloc(sizeof(char) * (ne_length + 1));
	if (new_entry == NULL) {
		return (env);
	}
	my_memset(new_entry, '\0', ne_length);
	new_entry = my_strcat(new_entry, key);
	new_entry = my_strcat(new_entry, "=");
	new_entry = my_strcat(new_entry, new_value);
	free(env[key_idx]);
	env[key_idx] = new_entry;
	return (env);
}

int	setenv_right_nb_args(int ac)
{
	return (ac == 2 || ac == 3);
}

void	setenv_handle_exceptions(int ac, shell_t *shell)
{
	if (ac > 3) {
		my_puterror(shell->prompt[0]);
		my_puterror(": Too many arguments.\n");
	} else
		my_show_word_array(shell->env);
}

shell_t	*run_ms_setenv(shell_t *shell)
{
	char	*key = NULL;
	char	*value = NULL;
	int	key_idx = -1;

	if (shell->prompt == NULL || shell->env == NULL) {
		return (shell);
	}
	key = shell->prompt[1];
	value = (shell->prompt[2] != NULL) ? shell->prompt[2] : "";
	key_idx = get_env_key_idx(shell->env, key);
	if (key_idx < 0) {
		shell->env = setenv_append(shell->env, key, value);
	} else {
		shell->env = setenv_replace(shell->env, key, value, key_idx);
	}
	return (shell);
}

void	ms_setenv_handle(shell_t *shell)
{
	int	ac = my_strtablen(shell->prompt);

	if (setenv_right_nb_args(ac) && shell->env) {
		shell = run_ms_setenv(shell);
	} else if (shell->env) {
		setenv_handle_exceptions(ac, shell);
	}
	if (path_needs_update(shell)) {
		shell->paths = set_path_from_env(shell->env);
	}
}
