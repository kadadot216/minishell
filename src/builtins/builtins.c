/*
** EPITECH PROJECT, 2018
** builtins.c
** File description:
** Shell builtins commands
*/

#include <stdlib.h>
#include "builtins/builtins.h"
#include "my.h"

void	ms_setenv(char **prompt, char ***env)
{
	int	ac = my_strtablen(prompt);
	int	envlen = 0;
	char	**envbackup = NULL;
	char	*new_var = NULL;
	int	newvar_len = 0;

	if (ac == 2) {
		newvar_len = (my_strlen(prompt[0]) + my_strlen(prompt[1]) + 2);
		envlen = my_strtablen(*env);
		envbackup = my_strtabdup(*env);
		free(*env);
		*env = malloc(sizeof(char *) * (envlen + 2));
		*env = my_strtabcpy(*env, (const char **) envbackup);
		my_memset(new_var, '\0', newvar_len);
		my_strcat(new_var, prompt[0]);
		my_strcat(new_var, "=");
		my_strcat(new_var, prompt[1]);
	}
}

void	ms_unsetenv(char **prompt, char ***env)
{

}

void	ms_cd(char *prompt, char ***env)
{

}

void	ms_exit(void)
{
	exit(0);
}

builtins_cmd_t	*init_builtins_cmds(void)
{
	builtins_cmd_t	builtins_cmds[4] = {
		{"setenv", &ms_setenv},
		{"unsetenv", &ms_unsetenv},
		{"cd", &ms_cd},
		{"cd", &ms_exit},
	};
	builtins_cmd_t	*builtins_cmd_ptr = builtins_cmds;

	return (builtins_cmd_ptr);
}


char	**launch_builtins(char **prompt, char **env)
{
	builtins_cmd_t	*builtins_cmds = init_builtins_cmds();
	return (env);
}
