/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include "my.h"
#include "main.h"
#include "prompt.h"
#include <stdlib.h>

int	main(int ac, char **av, char **ae)
{
	struct stat	sb;
	char	**my_env = my_strtabdup(ae);
	char	*p = NULL;

	while (wait_for_prompt(&p)) {
		my_putstr(p);
		my_putchar('\n');
	}

	return (0);
}
