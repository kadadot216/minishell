/*
** EPITECH PROJECT, 2018
** my_remove_trailing_spaces.c
** File description:
** Remove trailing spaces at end of string
*/

#include <stdlib.h>

char	*my_remove_trailing_spaces(char *str)
{
	int	i = 0;

	while (str[i+1] != '\0')
		i++;
	while (str[i] == ' ' || str[i] == 0377) {
		str[i] = '\0';
		i--;
	}
	return (str);
}
