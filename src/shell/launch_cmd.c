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

	while (paths != NULL && paths[i] != NULL) {
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


void	launch_cmd(shell_t *shell)
{
	char	*exec_bin = NULL;
	
	exec_bin = search_exec(shell->prompt[0], shell->paths);
	if (exec_bin != NULL) {
		exec_fork(exec_bin, shell->prompt, shell->env);
		free(exec_bin);
	}
}

prompt_cmd_t	get_cmd_type(char *cmd)
{
	if (my_strcmp(cmd, "exit") == 0)
		return (CMD_EXIT);
	if (my_strcmp(cmd, "setenv") == 0)
		return (CMD_SETENV);
	if (my_strcmp(cmd, "unsetenv") == 0)
		return (CMD_UNSETENV);
	if (my_strcmp(cmd, "cd") == 0)
		return (CMD_CD);
	else
		return (CMD_PATH);
}

prompt_cmd_t	check_prompt_type(char **prompt)
{
	char	*cmd = NULL;

	cmd = prompt[0];
	if (cmd[0] == '\0') {
		my_putstr("This is CR\n");
		return (CR);
	} else {
		return (get_cmd_type(cmd));
	}
}

void	launch_builtin(shell_t *shell)
{
	my_putstr("This is builtin!\n");
}

prompt_cmd_t	reset_prompt_type(void)
{
	return (NUL);
}

int	is_a_builtin(prompt_cmd_t pcmd)
{
	return (pcmd & (CMD_EXIT ^ CMD_SETENV ^ CMD_UNSETENV ^ CMD_CD));
}

void	dispatch_command(shell_t *shell)
{
	shell->pcmd = check_prompt_type(shell->prompt);
	if (shell->pcmd == CMD_PATH)
		launch_cmd(shell);
	if (is_a_builtin(shell->pcmd)) {
		my_putstr("This is a builtin\n");
		launch_builtin(shell);
	}
	shell->pcmd = reset_prompt_type();
}
