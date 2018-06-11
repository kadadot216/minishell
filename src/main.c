/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for mysh
*/

#include "my.h"
#include "main.h"

int	main(int ac, char **av)
{
	struct stat	sb;

	if (!check_for_args(ac) || !stat_path(av[1], &sb))
		return (84);
	return (0);
}
