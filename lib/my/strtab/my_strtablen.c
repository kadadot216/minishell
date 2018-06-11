/*
** EPITECH PROJECT, 2018
** my_strtablen.c
** File description:
** Returns the size of a strtab
*/

int	my_strtablen(char **tab)
{
	int	len = 0;

	while (tab[len] != 0)
		len++;
	return (len);
}
