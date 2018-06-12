/*
** EPITECH PROJECT, 2018
** getenv.c
** File description:
** env related functions
*/

#include <stdlib.h>
#include "my.h"

char	*my_getenv(char **env, char *var)
{
	int	i = 0;
	char	*value = NULL;

	while (env[i] != NULL) {
		if (my_strncmp(var, env[i], my_strlen(var)) == 0) {
			value = env[i];
			value += (my_strlen(var) + 1);
			return (value);
		}
		i++;
	}
	return (0);
}
