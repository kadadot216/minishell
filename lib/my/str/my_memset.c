/*
** EPITECH PROJECT, 2018
** my_memset.c
** File description:
** Fills an empty string with a char
*/

void	my_memset(char *str, char c, unsigned int size)
{
	int	i = 0;

	while (i < size) {
		str[i] = c;
		i++;
	}
}
