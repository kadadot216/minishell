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
#include "my.h"

char	*create_path_entry(char *key, char *value)
{
	int	key_end = 0;
	int	value_end = 0;
	char	*path_entry = NULL;

	if (key == NULL) {
		return (NULL);
	}
	key_end = my_strlen(key);
	value_end = my_strlen(value);
	path_entry = malloc(sizeof(char) * (key_end + value_end + 2));
	path_entry = my_strcat(path_entry, key);
	path_entry = my_strcat(path_entry, "=");
	path_entry = my_strcat(path_entry, (value != NULL) ? value : "");
	return (path_entry);
}

char	**setenv_append(char **env, char **prompt)
{
	int	height = 0;
	char	*path_entry = NULL;
	char	**env_tmp = NULL;

	if (env == NULL || prompt == NULL) {
		return (NULL);
	}
	env_tmp = my_strtabdup(env);
	height = my_strtablen(env);
	env = my_strtab_realloc(env, (height + 1));
	env = my_strtab_nclone(env, env_tmp, height);
	free(env_tmp);
	path_entry = create_path_entry(prompt[0], prompt[1]);
	env[height] = path_entry;
	return (env);
}

void	ms_setenv(shell_t *shell)
{
	int	ac = my_strtablen(shell->prompt);
	char	*exec_env = NULL;

	if ((ac == 2 || ac == 3) && shell->env) {
		shell->env = setenv_append(shell->env, &shell->prompt[1]);

	} else if (ac > 3){
		my_puterror(shell->prompt[0]);
		my_puterror(": Too many arguments.\n");
	} else {
		exec_env = search_exec("env", shell->paths);
		exec_fork(exec_env, shell->paths, shell->env);
	}
}
