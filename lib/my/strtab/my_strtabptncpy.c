/*
** EPITECH PROJECT, 2018
** my_strtabptncpy.c
** File description:
** Assigns an already allocated string into another char ** variable
** unset the previous char ** up to n
*/

#include <stdlib.h>

char	**my_strtabptncpy(char **dest, char **src, int n)
{
	int	i = 0;

	if (src == NULL) {
		return (NULL);
	}
	while (src[i] != NULL && dest[i] == NULL && i < n) {
		dest[i] = src[i];
		src[i] = NULL;
		i++;
	}
	return (dest);
}
