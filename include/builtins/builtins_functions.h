/*
** EPITECH PROJECT, 2018
** builtins_fuctions.h
** File description:
** Functions prototypes for builtins
*/

#ifndef __BUILTINS_FUNCTIONS_H__
#define __BUILTINS_FUNCTIONS_H__

#include "shell/shell.h"
#include "builtin_types.h"


void	ms_setenv_handle(shell_t *shell);
void	ms_unsetenv_handle(shell_t *shell);
void	ms_exit_handle(shell_t *shell, builtins_cmd_t *builtins);
void	ms_cd_handle(shell_t *shell);

#endif
