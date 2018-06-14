/*
** EPITECH PROJECT, 2018
** getenv.c
** File description:
** env related functions
*/

#include <stdlib.h>
#include "my.h"

char	*get_env_entry(char **env, char *key)
{
	int	i = 0;
	int	key_end = my_strlen(key);
	char	*value = NULL;

	if (!key_end)
		return (NULL);
	while (env[i] != NULL) {
		if (my_strncmp(key, env[i], key_end) == 0) {
			value = env[i];
			value += (key_end + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}
