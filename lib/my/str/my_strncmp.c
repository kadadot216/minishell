/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Compares n bytes of two strings
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;

	while (s1[i] != '\0' && i < n) {
		if (s2[i] == '\0')
			return (1);
		else if (s2[i] > s1[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s2[i] != '\0' && i < n)
		return (-1);
	return (0);
}
