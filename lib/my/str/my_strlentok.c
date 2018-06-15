/*
** EPITECH PROJECT, 2018
** my_strlentok.c
** File description:
** Counts the number of characters in str prior to c char
*/

int	my_strlentok(char const *str, char const c)
{
	int	str_count = 0;

	while (*str != '\0' && *str != c) {
		str_count++;
		str++;
	}
	return (str_count);
}

