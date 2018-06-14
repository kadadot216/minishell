/*
** EPITECH PROJECT, 2018
** builtins_fuctions.h
** File description:
** Functions prototypes for builtins
*/

#ifndef __BUILTINS_FUNCTIONS_H__
#define __BUILTINS_FUNCTIONS_H__

#include "shell/shell.h"

typedef	void (*builtin_fct)(shell_t *shell);

void	ms_setenv(shell_t *shell);
void	ms_unsetenv(shell_t *shell);
void	ms_exit(shell_t *shell);
void	ms_cd(shell_t *shell);

#endif
