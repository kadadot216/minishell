/*
** EPITECH PROJECT, 2018
** my_strtabcpy.c
** File description:
** Copy the contents from one strtab to another
*/

char	**my_strtabcpy(char **dest, const char **src)
{
	int	i = 0;
	int	j = 0;

	while (src[j] != 0) {
		while (src[j][i] != '\0') {
			dest[j][i] = src[j][i];
			i++;
		}
		dest[j][i] = '\0';
		i = 0;
		j++;
	}
	dest[j] = 0;
	return (dest);
}
