/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>
#include "str.h"

char	*my_strdup(char const *src)
{
	int	i = 0;
	int	slen = my_strlen(src);
	char	*copy;

	copy = malloc(sizeof(*src) * (slen + 1));
	my_memset(copy, '\0', slen);
	while (src[i] != '\0') {
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
