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
#include "builtins/builtins.h"
#include "shell/shell.h"

static char	*get_exec_fp(char const *path, char const *exec_prompt)
{
	int	exec_fp_length = (my_strlen(path) + my_strlen(exec_prompt) + 1);
	char	*exec_fp = malloc(exec_fp_length + 1);

	my_memset(exec_fp, '\0', exec_fp_length);
	my_strcat(exec_fp, path);
	my_strcat(exec_fp, "/");
	my_strcat(exec_fp, exec_prompt);
	return (exec_fp);
}

static char	*search_exec(char *exec_prompt, path_t *paths)
{
	int	i = 0;
	char	*exec_fp = NULL;

	while (paths[i] != NULL) {
		exec_fp = get_exec_fp(paths[i], exec_prompt);
		if (access(exec_fp, F_OK) == 0 && access(exec_fp, X_OK) == 0)
			return (exec_fp);
		else {
			free(exec_fp);
			i++;
		}
	}
	my_puterror(exec_prompt);
	my_puterror(": Command not found.\n");
	return (NULL);
}

static void	exec_fork(char *exec_bin, char **prompt, char **env)
{
	pid_t	pid = fork();

	if (pid < 0)
		my_puterror("Forking error\n");
	else if (pid == 0)
		execve(exec_bin, prompt, env);
	wait(&pid);
}

int	launch_cmd(shell_t shell)
{
	char	*exec_bin = NULL;
	
	if (shell->prompt[0][0] != '\0')
		exec_bin = search_exec(shell->prompt[0], shell->paths);
	if (exec_bin != NULL) {
		exec_fork(exec_bin, shell->prompt, shell->env);
		free(exec_bin);
		return (1);
	} else {
		return (0);
	}
}