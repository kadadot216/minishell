/*
** EPITECH PROJECT, 2018
** my_strndup.c
** File description:
** Allocates memory and copies the string given as argument in it 
** up to n characters
*/

#include <stdlib.h>
#include "str.h"

char	*my_strndup(char const *src, int n)
{
	int	i = 0;
	char	*copy;

	copy = malloc(sizeof(*src) * (n + 1));
	my_memset(copy, '\0', n);
	while (src[i] != '\0' && i < n) {
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

