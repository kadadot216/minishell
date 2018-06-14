/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for shell.c
*/

#ifndef __SHELL_H__
#define __SHELL_H__

#include "prompt.h"
#include "env.h"

typedef char*	path_t;

typedef struct	shell_s {
	path_t		*paths;
	char		**env;
	prompt_t	prompt;
} *shell_t;

#endif
