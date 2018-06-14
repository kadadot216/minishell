/*
** EPITECH PROJECT, 2018
** prompt_check.h
** File description:
** Header file for prompt_check.c
*/

#ifndef __PROMPT_CHECK_H__
#define __PROMPT_CHECK_H__

typedef enum	prompt_cmd_e {
	NUL = 0,
	CR = 1,
	CMD_SETENV = 2,
	CMD_UNSETENV = 4,
	CMD_EXIT = 8,
	CMD_CD = 16,
	CMD_PATH = 32,
} prompt_cmd_t;

int		is_a_builtin(prompt_cmd_t pcmd);
prompt_cmd_t	check_prompt_type(char **prompt);
prompt_cmd_t	reset_prompt_type(void);

#endif
