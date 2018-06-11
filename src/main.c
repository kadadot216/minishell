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
	char	**path = my_strtotab(get_env(env, "PATH"), ":");
	//my_show_word_array(path);
	//execve("/bin/ls", NULL, env);
	execve(prompt[0], prompt, env);
	my_free_strtab(path);
}


int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**env = my_strtabdup(ae);
	char	**prompt = wait_for_prompt(prompt);

	while (prompt_is_valid(prompt)) {
		my_show_word_array(prompt);
		launch_cmd(prompt, env);
		my_free_strtab(prompt);
		prompt = wait_for_prompt(prompt);
	}
	return (0);
}
