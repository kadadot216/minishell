/*
** EPITECH PROJECT, 2018
** getenv.c
** File description:
** env related functions
*/

#include <stdlib.h>
#include "my.h"


/* Returns the separator '=' position, if it returns 0 then,
 * this is invalid */
// Delete when useless
int	get_sep_pos(char *env_line)
{
	int	i = 0;

	while (env_line[i] != '\0') {
		if (env_line[i] == '=') {
			return (i);
		}
		i++;
	}
	return (0);
}

char	*get_env_entry(char **env, char *key)
{
	int	i = 0;
	int	key_end = my_strlen(key);
	char	*value = NULL;

	while (env[i] != NULL) {
		if (my_strncmp(key, env[i], key_end) == 0) {
			value = env[i];
			value += (key_end + 1);
			return (value);
		}
		i++;
	}
	return (0);
}
