/*
** EPITECH PROJECT, 2018
** ms_cd.c
** File description:
** cd builtin function declaration
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"
#include "builtins/cd.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	cd_right_nb_args(int ac)
{
	return (ac == 1 || ac == 2);
}

void	cd_handle_exceptions(shell_t *shell)
{
	my_puterror(shell->prompt[0]);
	my_puterror(": Too many arguments.\n");
}

int	arg_uses_currdir_notation(char const *arg)
{
	return (arg != NULL && arg[0] == '.' &&
		(arg[1] == '/' || arg[1] == '\0'));
}

int	arg_uses_parentdir_notation(char const *arg)
{
	return (arg != NULL && arg[0] == '.' && arg[1] == '.' &&
		(arg[2] == '/' || arg[2] == '\0'));
}

char	*cd_sanitize_parentdir(char *arg)
{
	int	i = 0;

	i = 3;
	while (arg[i] != '\0') {
		arg[i-3] = arg[i];
		i++;
	}
	arg[i-3] = '\0';
	arg[i-2] = '\0';
	arg[i-1] = '\0';
	arg[i] = '\0';
	return (arg);
}

char	*cd_sanitize_currdir(char *arg)
{
	int	i = 0;

	i = 2;
	while (arg[i] != '\0') {
		arg[i-2] = arg[i];
		i++;
	}
	arg[i-2] = '\0';
	arg[i-1] = '\0';
	arg[i] = '\0';
	return (arg);
}

char	*cd_cut_path_tail(char *cwd)
{
	int	i = my_strlen(cwd);

	if (cwd[i] == '/') {
		cwd[i] = '\0';
		i--;
	}
	while (cwd[i] != '/') {
		cwd[i] = '\0';
		i--;
	}
	cwd[i] = '\0';
	return (cwd);
}

void	cd_sanitize_exceptions(char *arg, char *cwd)
{
	if (arg_uses_currdir_notation(arg))
		arg = cd_sanitize_currdir(arg);
	if (arg_uses_parentdir_notation(arg)) {
		arg = cd_sanitize_parentdir(arg);
		cwd = cd_cut_path_tail(cwd);
	}
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
	// delete
	my_putstr(target_dir);
	my_putchar('\n');
	//
	free(cwd_tmp);
	return (target_dir);
}

char	*setup_cd_path(shell_t *shell, char *last_dir)
{
	char	*target_dir = NULL;
	char	*arg = shell->prompt[1];

	if (arg == NULL) {
		target_dir = my_strdup(shell->homedir);
	} else if (arg[0] == '-') {
		target_dir = my_strdup(last_dir);
	} else {
		target_dir = expand_cd_path(shell->cwd, arg);
	}
	return (target_dir);
}

int	cd_is_a_directory(struct stat *snode)
{
	if ((snode->st_mode & S_IFMT) == S_IFDIR) {
		return (CD_ISDIR);
	} else {
		return (CD_NOTDIR);
	}
}

int	test_cd_path(char *cd_path)
{
	struct stat	cd_path_stat;
	int	stat_status = -1;
	int	is_dir_status = 0;

	stat_status = stat(cd_path, &cd_path_stat);
	if (stat_status == -1) {
		return (stat_status);
	} else {
		is_dir_status = cd_is_a_directory(&cd_path_stat);
		return (is_dir_status);
	}
}

void	interpret_cd_status(enum cd_checking_status_e status, char **prompt)
{
	if (status == CD_NOTDIR) {
		my_puterror(prompt[1]);
		my_puterror(": Not a directory: ");
		my_putchar('\n');
	} else if (status == CD_NEXISTS) {
		my_puterror(prompt[1]);
		my_puterror(": No such file or directory\n");
	}
}

shell_t	*run_ms_cd(shell_t *shell)
{
	char	*last_dir = my_strdup(shell->cwd);
	char	*target_dir = NULL;
	int	test_cd_status = -1;
	int	chstatus = -1;

	target_dir = setup_cd_path(shell, last_dir);
	test_cd_status = test_cd_path(target_dir);
	if (test_cd_status == CD_ISDIR) {
		chstatus = chdir(target_dir);
	}
	if (chstatus == 0) {
		shell->cwd = ms_cd_get_cd();
	}
	interpret_cd_status(test_cd_status, shell->prompt);
	my_putstr("Target dir : ");
	my_putstr(target_dir);
	my_putchar('\n');
	free(target_dir);
	free(last_dir);
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
