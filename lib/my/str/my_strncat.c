/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** Concatenate n first characters of src
*/

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i = 0;
	int	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' || j < nb) {
		dest[i+j] = src[j];
		j++;
	}
	dest[i+j] = '\0';
	return (dest);
}

