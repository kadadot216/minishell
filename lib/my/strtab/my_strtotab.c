/*
** EPITECH PROJECT, 2018
** my_strtotab.c
** File description:
** Transforms a str into a str array delimited from another str
*/

#include <stdlib.h>
#include "str.h"

static int	match_delim(char *str, const char *delim, int n)
{
	if (str[0] == delim[0] && my_strncmp(str, delim, n) == 0)
		return (1);
	else
		return (0);
}

static int	count_toks(char *str, const char *delim, int sdelim)
{
	int	i = 0;
	int	tokens = 0;

	while (str[i] != '\0') {
		if (match_delim(&str[i], delim, sdelim))
			tokens++;
		i++;
	}
	return (tokens);
}

static char	*append_str_to_tab(char *str, int i, int w)
{
	char	*dest = malloc(sizeof(char) * (w + 1));

	my_strncpy(dest, &str[i-w], w);
	dest[w] = '\0';
	return (dest);
}

char	**my_strtotab(char *str, const char *delim)
{
	int	i = 0;
	int	w = 0;
	int	dl = my_strlen(delim);
	int	t = (count_toks(str, delim, dl) + 1);
	char	**tab = malloc(sizeof(char *) * (t + 1));

	tab[t] = NULL;
	t = 0;
	while (str[i] != '\0') {
		if (match_delim(&str[i], delim, dl)){
			tab[t] = append_str_to_tab(str, i, w);
			i += (dl - 1);
			w = 0;
			t++;
		} else
			w++;
		i++;
	}
	tab[t] = append_str_to_tab(str, i, w);
	return (tab);
}
