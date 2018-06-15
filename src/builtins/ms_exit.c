/*
** EPITECH PROJECT, 2018
** ms_exit.c
** File description:
** exit builtin function declaration
*/

#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "builtins/builtin_types.h"
#include "builtins/builtins_helpers.h"

void	ms_exit_handle(shell_t *shell, builtins_cmd_t *builtins)
{
	my_putstr(builtins[IDX_CMD_EXIT].cmd_name);
	my_putchar('\n');
	shell = unset_shell(shell);
	builtins = clear_builtins(builtins);
	exit(0);
}
