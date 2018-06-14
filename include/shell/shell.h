/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for shell.c
*/

#ifndef __SHELL_H__
#define __SHELL_H__

#include "prompt.h"

typedef char*	path_t;

typedef struct	shell_s {
	path_t	*paths;
	char	**env;
	char	**prompt;
} *shell_t;

shell_t	unset_shell(shell_t shell);
shell_t	setup_shell(char **ae);

#endif