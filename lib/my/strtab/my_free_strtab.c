/*
** EPITECH PROJECT, 2018
** my_free_strtab.c
** File description:
** Frees a malloc'd strtab
*/

#include <stdlib.h>

int	my_free_strtab(char **tab, int height)
{
	int	i = 0;

	while (i < height) {
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	free(tab);
	tab = NULL;
	if (tab == NULL)
		return (1);
	else
		return (0);
}
