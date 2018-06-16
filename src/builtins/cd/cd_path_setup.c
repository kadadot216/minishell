/*
** EPITECH PROJECT, 2018
** cd_path_setup.c
** File description:
** Path building related functions for ms_cd builtin
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "builtins/cd.h"

static char	*expand_cd_path(char *cwd, char *arg)
{
	char	*target_dir = NULL;
	char	*cwd_tmp = NULL;
	int	target_dir_len = 0;

	if (cwd == NULL || arg == NULL) {
		return (target_dir);
	}
	cwd_tmp = my_strdup(cwd);
	cd_sanitize_exceptions(arg, cwd_tmp);
	target_dir_len = (my_strlen(cwd_tmp) + my_strlen(arg) + 1);
	target_dir = malloc(sizeof(char) * target_dir_len + 1);
	my_memset(target_dir, '\0', target_dir_len);
	my_strcat(target_dir, cwd_tmp);
	my_strcat(target_dir, "/");
	my_strcat(target_dir, arg);
	free(cwd_tmp);
	return (target_dir);
}

char	*setup_cd_path(shell_t *shell)
{
	static char	last_dir[GETCWD_MAXSIZE] = {'\0'};
	char	*target_dir = NULL;
	char	*arg = shell->prompt[1];

	init_last_dir_once(last_dir, shell->cwd);
	if (arg == NULL) {
		target_dir = my_strdup(shell->homedir);
	} else if (arg[0] == '-') {
		target_dir = my_strdup(last_dir);
		update_last_dir(last_dir, shell->cwd);
	} else {
		update_last_dir(last_dir, shell->cwd);
		target_dir = expand_cd_path(shell->cwd, arg);
	}
	return (target_dir);
}
