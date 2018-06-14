/*
** EPITECH PROJECT, 2018
** builtins.h
** File description:
** Header file for builtins.c
*/

#ifndef __BUILTINS_H__
#define __BUILTINS_H__

#include "shell/prompt_type.h"

typedef	void (*builtin_fct)();

typedef struct	builtins_cmd_s {
	pcmd_t		pcmd;
	char		*cmd_name;
	builtin_fct	cmd_fct;
} builtins_cmd_t;

char	**launch_builtins(char **prompt, char **env);

#endif
