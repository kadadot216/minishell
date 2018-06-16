/*
** EPITECH PROJECT, 2018
** cd_checking.c
** File description:
** Checking functions for ms_cd builtin
*/

#include <stdlib.h>
#include "builtins/cd.h"
#include "my.h"

int	cd_right_nb_args(int ac)
{
	return (ac == 1 || ac == 2);
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

int	test_absolute_path(char **prompt)
{
	return (prompt != NULL && prompt[1] != NULL
		&& prompt[1][0] != '\0' && prompt[1][0] == '/');
}
