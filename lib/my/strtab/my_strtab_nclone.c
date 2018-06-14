/*
** EPITECH PROJECT, 2018
** my_strtab_nclone.c
** File description:
** Allocate and copy each string up to n from src to dest
** dest must have already allocated pointers to char
** Needs my_strdup.c
*/

#include "str.h"

char	**my_strtab_nclone(char **dest, char *const *src, int n)
{
	int	i = 0;

	while (src != 0 && dest[i] == 0 && i < n) {
		dest[i] = my_strdup(src[i]);
		i++;
	}
	return (dest);
}
