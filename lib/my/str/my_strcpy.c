/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** Copies n chars of a string variable into another variable 
*/

char	*my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
