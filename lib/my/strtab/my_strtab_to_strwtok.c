/*
** EPITECH PROJECT, 2018
** my_strtab_to_strwtok.c
** File description:
** Converts an strtab into a str and add a delim between each elem
*/

#include <stdlib.h>
#include "str.h"
#include "strtab.h"

// TODO: Refactor the function

char	*my_strtab_to_strwtok(char **tab, char *delim)
{
	char	*dest = NULL;
	int	tlength = 0;
	int	height = 0;
	int	delim_length = 0;
	int	i = 0;
	
	if (tab == NULL || delim == NULL) {
		return (NULL);
	}
	height = my_strtablen(tab);
	delim_length = my_strlen(delim);
	while (i < height) {
		tlength += (my_strlen(tab[i]) + delim_length);
		i++;	
	}
	i = 0;
	dest = malloc(sizeof(char) * tlength);
	my_memset(dest, '\0', tlength);
	while (i < height) {
		my_strcat(dest, tab[i]);
		my_strcat(dest, delim);
		i++;
	}
	dest[tlength - 1] = '\0';
	return (dest);
}
