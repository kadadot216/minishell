/*
** EPITECH PROJECT, 2018
** ms_setenv_checking.c
** File description:
** Check related functions for ms_setenv
*/

int	setenv_right_nb_args(int ac)
{
	return (ac == 2 || ac == 3);
}
