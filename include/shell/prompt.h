/*
** EPITECH PROJECT, 2018
** prompt.h
** File description:
** Header file for prompt.c
*/

#ifndef __PROMPT_H__
#define __PROMPT_H__

int	is_prompt_allocated(char **prompt);
char	**wait_for_prompt(char *cwd);
char	**set_prompt(char *input);

#endif
