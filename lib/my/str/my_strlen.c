/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** RETUNRS the number of characters found in the string passed as parameter
*/

int	my_strlen(char const *str)
{
	int	str_count = 0;

	while (*str != '\0') {
		str_count++;
		str++;
	}
	return (str_count);
}
