/*
** EPITECH PROJECT, 2018
** builtins_t.h
** File description:
** Header file for builtins data types.c
*/

#ifndef __BUILTINS_T_H__
#define __BUILTINS_T_H__

typedef	void (*builtin_fct)();

typedef struct	builtins_cmd_s {
	char		*cmd_name;
	builtin_fct	cmd_fct;
} builtins_cmd_t;

#endif
