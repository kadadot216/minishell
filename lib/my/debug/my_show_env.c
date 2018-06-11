/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** Display formatted env
*/

#include "my.h"

int	my_show_env(char *const *env)
{
	int	i = 0;

	while (env[i] != 0) {
		my_putstr(env[i]);
		my_putchar('\n');
		i++;
	}
	return (0);
}
