/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompt utilities functions
*/

#include "my.h"
#include "gnl.h"
#include <stdlib.h>

int	my_strtab_isvalid(char *const *tab)
{
	return (tab[0] != NULL);
}

int	wait_for_prompt(char ***prompt)
{
	my_putstr("$>");
	*prompt = my_strtotab(get_next_line(0), " ");
	return (my_strtab_isvalid(*prompt));
}
