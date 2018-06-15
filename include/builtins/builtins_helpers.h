/*
** EPITECH PROJECT, 2018
** builtins.h
** File description:
** Header file for builtins.c
*/

#ifndef __BUILTINS_H__
#define __BUILTINS_H__

#include "builtin_types.h"

int	get_fct_idx_from_pcmd(builtins_cmd_t *builtins, pcmd_t pcmd);
pcmd_t	check_prompt_from_builtins(builtins_cmd_t *builtins, char **prompt);
char	**launch_builtins(char **prompt, char **env);
builtins_cmd_t	*get_builtins_cmd_table(void);
builtins_cmd_t	*clear_builtins(builtins_cmd_t *builtins);

#endif
