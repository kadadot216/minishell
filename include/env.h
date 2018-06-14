/*
** EPITECH PROJECT, 2018
** env.h
** File description:
** Header file for env.c
*/

#ifndef __ENV_H__
#define __ENV_H__

typedef	struct env_entry_s {
	char *key;
	char *value;
} *env_entry_t;

typedef struct env_stack_s {
	env_entry_t	*stack;
	int		stacksize;
} env_stack_t;

#endif
