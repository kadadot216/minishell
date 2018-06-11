/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Displays, one-by-one, the characters of a string
*/

#include <unistd.h>

int	my_putstr(const char *str)
{
	unsigned int	i = 0;

	while (str[i] != '\0')
		i++;
	write(1, str, i);
	return (0);
}
