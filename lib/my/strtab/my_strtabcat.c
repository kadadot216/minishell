/*
** EPITECH PROJECT, 2018
** my_strtabcat.c
** File description:
** Concatenate two arrays of strtabs together
*/

#include <stdlib.h>
#include "strtab.h"

char	**my_strtabcat(char **dest, char **src)
{
	int	i = 0;
	int	j = 0;
	int	src_length = 0;

	if (dest == NULL || src == NULL) {
		return (dest);
	}
	i = my_strtablen(dest);
	src_length = my_strtablen(src);
	while (j < src_length) {
		dest[i+j] = src[j];
		j++;
	}
	return (dest);
}
