/*
** EPITECH PROJECT, 2018
** my_strtab_null.c
** File description:
** Sets all pointers of a strtab to NULL
*/

#include <stdlib.h>
#include "strtab.h"

char	**my_strtab_null(char **tab, int height)
{
	int	i = 0;

	if (tab == NULL) {
		return (NULL);
	}
	while (i < height) {
		tab[i] = NULL;
		i++;
	}
	return (tab);
}
