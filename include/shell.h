/*
** EPITECH PROJECT, 2018
** shell.h
** File description:
** Header file for shell.c
*/

#ifndef __SHELL_H__
#define __SHELL_H__

#include "prompt.h"

typedef struct	shell_s {
	char		**env;
	char		**path;
	prompt_t	prompt;
} *shell_t;

#endif
