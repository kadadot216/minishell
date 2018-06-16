/*
** EPITECH PROJECT, 2018
** path_exec.c
** File description:
** Functions related to execute PATH commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
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

static int	can_access_command(char *cmd)
{
	return ((access(cmd, F_OK) == 0) && (access(cmd, X_OK) == 0));
}

static char	*search_exec_from_path(char *exec_prompt, char **paths)
{
	int	i = 0;
	char	*exec_fp = NULL;

	while (paths != NULL && paths[i] != NULL) {
		exec_fp = get_exec_fp(paths[i], exec_prompt);
		if (can_access_command(exec_fp))
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

void	launch_path_cmd(shell_t *shell)
{
	char	*cmd = shell->prompt[0];
	char	*exec_bin = NULL;

	if (can_access_command(cmd)) {
		exec_fork(cmd, shell->prompt, shell->env);
	}
	else {
		exec_bin = search_exec_from_path(cmd, shell->paths);
	}
	if (exec_bin != NULL) {
		cmd = NULL;
		exec_fork(exec_bin, shell->prompt, shell->env);
		free(exec_bin);
	}
}
