/*
** EPITECH PROJECT, 2018
** my_strtab_realloc.c
** File description:
** Reallocate a strtab with a given size
*/

#include <stdlib.h>
#include "strtab.h"

char	**my_strtab_realloc(char **env, int size)
{
	if (env == NULL || size < 0) {
		return (NULL);
	}
	env = my_free_strtab(env);
	env = malloc(sizeof(char *) * (size + 1));
	if (env == NULL) {
		return (NULL);
	}
	env = my_strtab_null(env, (size + 1));
	return (env);
}

