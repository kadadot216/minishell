/*
** EPITECH PROJECT, 2018
** my_free_strtab.c
** File description:
** Frees a malloc'd strtab
*/

#include <stdlib.h>
#include "strtab.h"

char	**my_free_strtab(char **tab)
{
	int	i = 0;
	int	height = my_strtablen(tab);

	while (i < height) {
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}
