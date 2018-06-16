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

void	cd_run_chdir(char *target_dir, shell_t *shell)
{
	int	test_cd_status = -1;
	int	chstatus = -1;

	test_cd_status = test_cd_path(target_dir);
	if (test_cd_status == CD_ISDIR) {
		chstatus = chdir(target_dir);
	}
	if (chstatus == 0) {
		shell->cwd = ms_cd_get_cd();
	}
	interpret_cd_status(test_cd_status, shell->prompt);
}

shell_t	*run_ms_cd(shell_t *shell)
{
	char	*target_dir = NULL;

	if (test_absolute_path(shell->prompt)) {
		cd_run_chdir(shell->prompt[1], shell);
	} else {
		target_dir = setup_cd_path(shell);
		cd_run_chdir(target_dir, shell);
		free(target_dir);
	}
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
