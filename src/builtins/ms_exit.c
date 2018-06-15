/*
** EPITECH PROJECT, 2018
** ms_exit.c
** File description:
** exit builtin function declaration
*/

#include <stdlib.h>
#include "shell/shell.h"

void	ms_exit_handle(shell_t *shell)
{
	unset_shell(shell);
	exit(0);
}
