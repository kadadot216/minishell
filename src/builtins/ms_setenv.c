/*
** EPITECH PROJECT, 2018
** ms_setenv.c
** File description:
** setenv builtin function declaration
*/

#include <stdlib.h>
#include "shell/shell.h"
#include "my.h"

void	ms_setenv(shell_t *shell)
{
	int	ac = my_strtablen(shell->prompt);
	int	envlen = 0;
	char	**envbackup = NULL;
	char	*new_var = NULL;
	int	newvar_len = 0;

	if (ac == 2) {
		newvar_len = (my_strlen(shell->prompt[0]) + my_strlen(shell->prompt[1]) + 2);
		envlen = my_strtablen(shell->env);
		envbackup = my_strtabdup(shell->env);
		free(shell->env);
		shell->env = malloc(sizeof(char *) * (envlen + 2));
		shell->env = my_strtabcpy(shell->env, (const char **) envbackup);
		my_memset(new_var, '\0', newvar_len);
		my_strcat(new_var, shell->prompt[0]);
		my_strcat(new_var, "=");
		my_strcat(new_var, shell->prompt[1]);
	}
}
