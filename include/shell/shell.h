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

typedef enum	prompt_cmd_e {
	NUL = 0,
	CR = 1,
	CMD_SETENV = 2,
	CMD_UNSETENV = 4,
	CMD_EXIT = 8,
	CMD_CD = 16,
	CMD_PATH = 32,
} prompt_cmd_t;

typedef struct	shell_s {
	path_t		*paths;
	char		**env;
	char		**prompt;
	prompt_cmd_t	pcmd;
} shell_t;

shell_t	*unset_shell(shell_t *shell);
shell_t	*setup_shell(char **ae);

#endif
