/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include <stdlib.h>
#include <unistd.h> //execve
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

void	launch_cmd(char **prompt, char **env)
{
	char	*path = get_env(env, "PATH");
	char	**pathtab = my_strtotab(path, ":");
	my_show_word_array(pathtab);
	my_free_strtab(pathtab);
}


int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**env = my_strtabdup(ae);
	char	**prompt = NULL;

	while (wait_for_prompt(&prompt)) {
		//my_show_word_array(prompt);
		//my_putchar('\n');
		launch_cmd(prompt, env);
		my_free_strtab(prompt);
	}
	return (0);
}
