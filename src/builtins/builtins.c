/*
** EPITECH PROJECT, 2018
** builtins.c
** File description:
** Shell builtins commands
*/

#include <stdlib.h>
#include "builtins/builtins.h"
#include "my.h"

void	ms_exit(shell_t *shell)
{
	exit(0);
}

void	ms_cd(shell_t *shell)
{

}

void	ms_unsetenv(shell_t *shell)
{

}

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

builtins_cmd_t	*get_builtins_cmd_table(void)
{
	builtins_cmd_t *cmd_table = NULL;
	builtins_cmd_t	BUILTINS_CMD_LIST[] = {
		{IDX_CMD_SETENV, CMD_SETENV, "setenv", &ms_setenv},
		{IDX_CMD_UNSETENV, CMD_UNSETENV, "unsetenv", &ms_unsetenv},
		{IDX_CMD_CD, CMD_CD, "cd", &ms_cd},
		{IDX_CMD_EXIT, CMD_EXIT, "exit", &ms_exit},
	};

	cmd_table = BUILTINS_CMD_LIST;
	return (cmd_table);
}
