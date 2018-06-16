/*
** EPITECH PROJECT, 2018
** launch_cmd.h
** File description:
** Header file for cmd.c
*/

#ifndef __LAUNCH_CMD_H__
#define __LAUNCH_CMD_H__

#include "shell.h"
#include "builtins/builtin_types.h"

int	is_a_builtin(builtins_cmd_t *builtins, pcmd_t pcmd);
void	dispatch_command(builtins_cmd_t *builtins, shell_t *shell);

#endif
