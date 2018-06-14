/*
** EPITECH PROJECT, 2018
** getenv.c
** File description:
** env related functions
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"

int	is_entry_unallocated(env_entry_t env)
{
	return (env != NULL);
}

int	is_entry_empty(env_entry_t env)
{
	if (!is_entry_unallocated(env)) {
		return (0);
	} else if (env->key == NULL && env->value == NULL) {
		return (1);
	} else {
		return (0);
	}
}

env_entry_t	set_empty_entry(void)
{
	env_entry_t	env = NULL;

	env = malloc(sizeof(env_entry_t));
	env->key = NULL;
	env->value = NULL;
	return (env);
}

void	remove_empty_entry(env_entry_t env)
{
	free(env);
	env = NULL;
}

env_entry_t	map_entry(char *env_line)
{
	int		tokenpos = 0;
	env_entry_t	env = NULL;
	
	env = set_empty_env();
	
}

env_stack_t	map_env(char **ae)
{
	env_entry_t	*env = NULL;

}



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
