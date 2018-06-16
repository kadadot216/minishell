/*
** EPITECH PROJECT, 2018
** ms_cd.c
** File description:
** cd builtin function declaration
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"


int	cd_right_nb_args(int ac)
{
	return (ac == 1 || ac == 2);
}

void	cd_handle_exceptions(shell_t *shell)
{
	my_puterror(shell->prompt[0]);
	my_puterror(": Too many arguments.\n");
}

char	*sanitize_cd_arg(char *arg)
{
	int	i = 0;

	if (arg[0] == '.' && arg[1] == '/') {
		i = 2;
		while (arg[i] != '\0') {
			arg[i-2] = arg[i];
			i++;
		}
		arg[i-2] = '\0';
		arg[i-1] = '\0';
		arg[i] = '\0';
		return (arg);
	} else {
		return (arg);
	}
}

char	*expand_cd_path(char *cwd, char *arg)
{
	char	*target_dir = NULL;
	int	target_dir_len = 0;

	if (cwd == NULL || arg == NULL) {
		return (target_dir);
	}
	arg = sanitize_cd_arg(arg);
	//cwd = sanitize_cd_cwd(cwd);
	target_dir_len = (my_strlen(cwd) + my_strlen(arg) + 1);
	target_dir = malloc(sizeof(char) * target_dir_len + 1);
	my_memset(target_dir, '\0', target_dir_len);
	my_strcat(target_dir, cwd);
	my_strcat(target_dir, "/");
	my_strcat(target_dir, arg);
	// delete
	my_putstr(target_dir);
	my_putchar('\n');
	//
	return (target_dir);
}

shell_t	*run_ms_cd(shell_t *shell)
{
	char	*target_dir = NULL;
	char	*last_dir = my_strdup(shell->cwd);
	char	*arg = shell->prompt[1];

	if (arg == NULL) {
		target_dir = my_strdup(shell->homedir);
	} else if (arg[0] == '-') {
		target_dir = my_strdup(last_dir);
	} else {
		target_dir = expand_cd_path(shell->cwd, arg);
	}
	//if (test_cd_path(target_dir))
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
