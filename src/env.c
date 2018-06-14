/*
** EPITECH PROJECT, 2018
** getenv.c
** File description:
** env related functions
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"

int	is_entry_allocated(env_entry_t env)
{
	return (env != NULL);
}

int	is_entry_empty(env_entry_t env)
{
	if (!is_entry_allocated(env)) {
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

void	remove_empty_entry(env_entry_t entry)
{
	free(entry);
	entry = NULL;
}

void		free_entry(env_entry_t entry)
{
	free(entry->key);
	entry->key = NULL;
	free(entry->value);
	entry->value = NULL;
	if (is_entry_empty(entry)) {
		remove_empty_entry(entry);
	}
}

/* Returns the separator '=' position, if it returns 0 then,
 * this is invalid */
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

env_entry_t	map_entry(char *entry_line)
{
	int		sep_pos = 0;
	int		length = 0;
	env_entry_t	entry = NULL;

	sep_pos = get_sep_pos(entry_line);
	if (sep_pos) {
		length = my_strlen(entry_line);
		entry = set_empty_entry();
		entry->key = my_strndup(entry_line, sep_pos);
		entry->value = my_strndup(&entry_line[sep_pos], (length - sep_pos));
	} else {
		return (NULL);
	}
}

int	is_env_stack_allocated(env_stack_t env)
{
	return (env != NULL);
}

int	is_env_stack_empty(env_stack_t env)
{

}

env_stack_t	set_empty_env_stack(void)
{
	env_stack_t	new = NULL;

	new = malloc(sizeof(env_stack_t));
	if (new == NULL) {
		return (NULL);
	} else {
		return (new);
	}
}

env_stack_t	map_env(char **ae)
{
	env_stack_t	env = NULL;
	int		env_length = my_strtablen(ae);

	if (!env_length) {
		return (NULL);
	}
	env = set_empty_env_stack();
	if ()
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
