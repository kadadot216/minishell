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
#include "launch_cmd.h"
#include "builtins.h"
#include "getenv.h"

#include "debug.h"

int	main(int ac, char **av, char **ae)
{
	char	**env = my_strtabdup(ae);
	char	**path = my_strtotab(my_getenv(env, "PATH"), ":");
	char	**prompt = wait_for_prompt(prompt);

	while (is_prompt_valid(prompt)) {
		if (!launch_cmd(prompt, env, path))
			env = launch_builtins(prompt, env);
		prompt = my_free_strtab(prompt);
		prompt = wait_for_prompt(prompt);
	}
	my_free_strtab(path);
	my_free_strtab(env);
	return (0);
}
