/*
** EPITECH PROJECT, 2018
** env.c
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
	char	*keyc = NULL;

	if (key == NULL || env == NULL)
		return (NULL);
	while (env[i] != NULL) {
		key_end = my_strlentok(env[i], '=');
		keyc = my_strndup(env[i], key_end);
		if (my_strcmp(key, keyc) == 0) {
			free(keyc);
			value = env[i];
			value += (key_end + 1);
			return (value);
		}
		free(keyc);
		i++;
	}
	return (NULL);
}

int	get_env_key_idx(char **env, char *key)
{
	int	idx = 0;
	int	key_end = 0;
	char	*keyc = NULL;

	if (key == NULL || env == NULL)
		return (-1);
	while (env[idx] != NULL) {
		key_end = my_strlentok(env[idx], '=');
		keyc = my_strndup(env[idx], key_end);
		if (my_strcmp(key, keyc) == 0) {
			free(keyc);
			return (idx);
		}
		free(keyc);
		idx++;
	}
	return (-1);
}

char	*create_env_entry(char *key, char *value)
{
	char	*env_entry = NULL;
	int	env_entry_length = 0;

	if (key == NULL) {
		return (key);
	}
	env_entry_length = (my_strlen(key) + my_strlen(value) + 1);
	env_entry = malloc(env_entry_length + 1);
	if (env_entry == NULL) {
		return (NULL);
	}
	my_memset(env_entry, '\0', env_entry_length);
	env_entry = my_strcat(env_entry, key);
	env_entry = my_strcat(env_entry, "=");
	env_entry = my_strcat(env_entry, value);
	return (env_entry);
}
