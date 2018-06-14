/*
** EPITECH PROJECT, 2018
** prompt_check.h
** File description:
** Header file for prompt_check.c
*/

#ifndef __PROMPT_CHECK_H__
#define __PROMPT_CHECK_H__

typedef enum	pcmd_e {
	NUL = 0,
	CR = 1,
	CMD_SETENV = 2,
	CMD_UNSETENV = 4,
	CMD_EXIT = 8,
	CMD_CD = 16,
	CMD_PATH = 32,
} pcmd_t;

typedef enum	pcmd_idx_e {
	IDX_NUL,
	IDX_CR,
	IDX_CMD_SETENV,
	IDX_CMD_UNSETENV,
	IDX_CMD_EXIT,
	IDX_CMD_CD,
	IDX_CMD_PATH
} pcmd_idx_t;

int	is_a_builtin(pcmd_t pcmd);
pcmd_t	check_prompt_type(char **prompt);
pcmd_t	reset_prompt_type(void);

#endif
