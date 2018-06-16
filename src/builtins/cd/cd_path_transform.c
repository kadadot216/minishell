/*
** EPITECH PROJECT, 2018
** cd_path_transform.c
** File description:
** Functions that transforms the path of args when needed
*/

#include "str.h"
#include "builtins/cd.h"

static char	*cd_sanitize_parentdir(char *arg)
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

static char	*cd_sanitize_currdir(char *arg)
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

static char	*cd_cut_path_tail(char *cwd)
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
