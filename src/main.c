/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include <unistd.h> //execve
#include "my.h"
#include "main.h"
#include "prompt.h"

#include "debug.h"

char	*get_env(char **env, char *var)
{
	int	i = 0;
	char	*value = NULL;

	while (env[i] != NULL) {
		if (my_strncmp(var, env[i], my_strlen(var)) == 0) {
			value = env[i];
			value += (my_strlen(var) + 1);
			return (value);
		}
		i++;
	}
	return (0);
}

char	*search_exec(char *exec_prompt, char **path)
{
	int	i = 0;
	char	*exec_fp = NULL;
	int	exec_fp_length = 0;

	while (path[i] != NULL) {
		exec_fp_length = (my_strlen(path[i]) + my_strlen(exec_prompt) + 1);
		exec_fp = malloc(exec_fp_length + 1);
		my_memset(exec_fp, '\0', exec_fp_length);
		my_strcat(exec_fp, path[i]);
		my_strcat(exec_fp, "/");
		my_strcat(exec_fp, exec_prompt);
		///
		my_putstr("Testing ");
		my_putstr(exec_fp);
		my_putchar('\n');
		///
		if (access(exec_fp, F_OK) == 0 && access(exec_fp, X_OK) == 0) {
			///
			my_putstr(exec_fp);
			my_putchar('\n');
			return (exec_fp);
			///
		} else {
			free(exec_fp);
			i++;
		}
	}
	my_putstr("Command not found.\n");
	return (NULL);
}

void	launch_cmd(char **prompt, char **env)
{
	char	**path = my_strtotab(get_env(env, "PATH"), ":");
	char	*exec_bin = search_exec(prompt[0], path);
	if (exec_bin != NULL)
		execve(exec_bin, prompt, env);
	my_putstr(exec_bin);
	free(exec_bin);
	my_free_strtab(path);
}


int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**env = my_strtabdup(ae);
	char	**prompt = wait_for_prompt(prompt);

	while (prompt_is_valid(prompt)) {
		launch_cmd(prompt, env);
		my_free_strtab(prompt);
		prompt = wait_for_prompt(prompt);
	}
	return (0);
}
