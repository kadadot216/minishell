/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Displays a char to the standard output
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
