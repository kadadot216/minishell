/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for shell.c
*/

#ifndef __SHELL_H__
#define __SHELL_H__

#include "prompt_type.h"

typedef struct	shell_s {
	char	*cwd;
	char	*homedir;
	char	**paths;
	char	**env;
	char	**prompt;
	pcmd_t	pcmd_f;
} shell_t;

int	path_needs_update(shell_t *shell);
char	**set_path_from_env(char **env);
shell_t	*unset_shell(shell_t *shell);
shell_t	*setup_shell(char **ae);

#endif
