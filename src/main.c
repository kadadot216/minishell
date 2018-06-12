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
#include "cmd.h"

#include "debug.h"

int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**env = my_strtabdup(ae);
	char	**prompt = wait_for_prompt(prompt);

	while (prompt_is_valid(prompt)) {
		launch_cmd(prompt, env);
		prompt = my_free_strtab(prompt);
		prompt = wait_for_prompt(prompt);
	}
	return (0);
}
