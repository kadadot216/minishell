/*
** EPITECH PROJECT, 2018
** ms_cd.c
** File description:
** cd builtin function declaration
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"
#include "builtins/cd.h"

void	cd_handle_exceptions(shell_t *shell)
{
	my_puterror(shell->prompt[0]);
	my_puterror(": Too many arguments.\n");
}

char	*expand_cd_path(char *cwd, char *arg)
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
	char	*target_dir = NULL;
	char	*arg = shell->prompt[1];

	if (arg == NULL) {
		target_dir = my_strdup(shell->homedir);
	} else if (arg[0] == '-') {
		target_dir = my_strdup(shell->cwd);
	} else {
		target_dir = expand_cd_path(shell->cwd, arg);
	}
	return (target_dir);
}

shell_t	*run_ms_cd(shell_t *shell)
{
	char	*target_dir = NULL;
	int	test_cd_status = -1;
	int	chstatus = -1;

	target_dir = setup_cd_path(shell);
	test_cd_status = test_cd_path(target_dir);
	if (test_cd_status == CD_ISDIR) {
		chstatus = chdir(target_dir);
	}
	if (chstatus == 0) {
		shell->cwd = ms_cd_get_cd();
	}
	interpret_cd_status(test_cd_status, shell->prompt);
	free(target_dir);
	return (shell);
}

void	ms_cd_handle(shell_t *shell)
{
	int	ac = my_strtablen(shell->prompt);

	if (cd_right_nb_args(ac) && shell->env) {
		shell = run_ms_cd(shell);
	} else {
		cd_handle_exceptions(shell);
	}
}
