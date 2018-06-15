/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for shell.c
*/

#ifndef __SHELL_H__
#define __SHELL_H__

#include "prompt_type.h"

typedef char*	path_t;

typedef struct	shell_s {
	path_t	*paths;
	char	**env;
	char	**prompt;
	pcmd_t	pcmd_f;
} shell_t;

shell_t	*unset_shell(shell_t *shell);
shell_t	*setup_shell(char **ae);
char	**set_path_from_env(char **env);

#endif
