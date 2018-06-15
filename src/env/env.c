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
	int	key_end = 0;
	char	*value = NULL;

	if (key == NULL || env == NULL)
		return (NULL);
	key_end = my_strlen(key);
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

int	get_env_key_idx(char **env, char *key)
{
	int	idx = 0;
	int	key_end = 0;

	if (key == NULL || env == NULL)
		return (-1);
	key_end = my_strlen(key);
	while (env[idx] != NULL) {
		if (my_strncmp(key, env[idx], key_end) == 0) {
			return (idx);
		}
		idx++;
	}
	return (-1);
}
