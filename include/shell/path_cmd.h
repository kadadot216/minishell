/*
** EPITECH PROJECT, 2018
** path_cmd.h
** File description:
** Header file for path_cmd.c function prototypes
*/

#ifndef __PATH_CMD_H__
#define __PATH_CMD_H__

#include "shell/shell.h"

void	launch_path_cmd(shell_t *shell);
void	exec_fork(char *exec_bin, char **prompt, char **env);
char	*search_exec(char *exec_prompt, char **paths);

#endif

