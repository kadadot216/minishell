/*
** EPITECH PROJECT, 2018
** env.h
** File description:
** Header file for env.c
*/

#ifndef __GETENV_H__
#define __GETENV_H__

int	get_env_key_idx(char **env, char *key);
char	*get_env_entry(char **env, char *var);
char	*create_env_entry(char *key, char *value);

#endif
