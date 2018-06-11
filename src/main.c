/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"
#include "prompt.h"

#include "debug.h"

char	*get_env(char **env, char *var)
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

int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**env = my_strtabdup(ae);
	char	*p = NULL;

	//my_show_word_array(env);
	my_putstr(get_env(env, "PATH"));
	my_putchar('\n');
	my_putstr(get_env(env, "PATH"));
	my_putchar('\n');
	while (wait_for_prompt(&p)) {
		my_putstr(p);
		my_putchar('\n');
	}
	return (0);
}
