/*
** EPITECH PROJECT, 2018
** my_puterror.c
** File description:
** Dispaly a message as char * in stderr
*/

#include <unistd.h>

void	my_puterror(char *strerr)
{
	int	i = 0;

	while (strerr[i] != '\0')
		i++;
	write(2, strerr, i);
}
