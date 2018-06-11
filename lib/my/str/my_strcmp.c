/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Compares two strings of characters
*/

int	my_strcmp(char const *s1, char const *s2)
{
	while (*s1 != '\0') {
		if (*s2 == '\0')
			return (1);
		else if (*s2 > *s1)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (-1);
	return (0);
}
