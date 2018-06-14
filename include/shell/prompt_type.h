/*
** EPITECH PROJECT, 2018
** prompt_type.h
** File description:
** Prompt checking function prototypes and data structures
*/

#ifndef __PROMPT_CHECK_H__
#define __PROMPT_CHECK_H__

typedef enum	pcmd_e {
	NUL = 0,
	CR = 1,
	CMD_EXEC = 2,
	CMD_SETENV = 4,
	CMD_UNSETENV = 8,
	CMD_CD = 16,
	CMD_EXIT = 32,
} pcmd_t;

typedef enum	pcmd_idx_e {
	IDX_CMD_SETENV,
	IDX_CMD_UNSETENV,
	IDX_CMD_CD,
	IDX_CMD_EXIT,
	IDX_PCMD_EOL
} pcmd_idx_t;

int	is_a_builtin(pcmd_t pcmd);
pcmd_t	reset_prompt_type(void);

#endif
