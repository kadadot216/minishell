/*
** EPITECH PROJECT, 2018
** cmd.c
** File description:
** Command handling functions
*/

#include <unistd.h> //execve
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "getenv.h"

static char	*get_exec_fp(char const *path_case, char const *exec_prompt)
{
	int	exec_fp_length = (my_strlen(path_case) + my_strlen(exec_prompt) + 1);
	char	*exec_fp = malloc(exec_fp_length + 1);

	my_memset(exec_fp, '\0', exec_fp_length);
	my_strcat(exec_fp, path_case);
	my_strcat(exec_fp, "/");
	my_strcat(exec_fp, exec_prompt);
	return (exec_fp);
}

static char	*search_exec(char *exec_prompt, char **path)
{
	int	i = 0;
	char	*exec_fp = NULL;

	while (path[i] != NULL) {
		exec_fp = get_exec_fp(path[i], exec_prompt);
		if (access(exec_fp, F_OK) == 0 && access(exec_fp, X_OK) == 0)
			return (exec_fp);
		else {
			free(exec_fp);
			i++;
		}
	}
	my_putstr(exec_prompt);
	my_putstr(": Command not found.\n");
	return (NULL);
}

void	launch_cmd(char **prompt, char **env)
{
	char	**path = my_strtotab(get_env(env, "PATH"), ":");
	char	*exec_bin = search_exec(prompt[0], path);
	pid_t	pid = fork();

	if (exec_bin != NULL && pid == 0)
		execve(exec_bin, prompt, env);
	wait(0);
	free(exec_bin);
	my_free_strtab(path);
}
