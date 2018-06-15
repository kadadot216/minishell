/*
** EPITECH PROJECT, 2018
** builtins_types.h
** File description:
** Header file for the builtin structure
*/

#ifndef __BUILTIN_TYPES_H__
#define __BUILTIN_TYPES_H__

#include "shell/prompt_type.h"

typedef	void (*builtin_fct)();

typedef struct	builtins_cmd_s {
	pcmd_idx_t	pcmd_idx;
	pcmd_t	pcmd;
	char	*cmd_name;
	builtin_fct	cmd_fct;
} builtins_cmd_t;

#endif
