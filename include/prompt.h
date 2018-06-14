/*
** EPITECH PROJECT, 2018
** prompt.h
** File description:
** Header file for prompt.c
*/

#ifndef __PROMPT_H__
#define __PROMPT_H__

typedef struct	prompt_s {
	char	*cmd;
	char	**args;
} *prompt_t;

int		is_prompt_valid(prompt_t prompt);
prompt_t	wait_for_prompt(void);
prompt_t 	set_prompt(char *input);

#endif
