/*
** EPITECH PROJECT, 2018
** my_strtabdup.c
** File description:
** Copies a strtab into another memory zone.
*/

#include "str.h"
#include "strtab.h"
#include <stdlib.h>

char	**my_strtabdup(char **tab)
{
	char	**dest = NULL;
	int	i = my_strtablen(tab);

	dest = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i] != 0) {
		dest[i] = my_strdup(tab[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
