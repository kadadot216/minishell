/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompt utilities functions
*/

#include "my.h"
#include "gnl.h"

int	my_str_isnull(char const *str)
{
	return (my_strcmp(str, "\0"));
}

int	wait_for_prompt(char **prompt)
{
	my_putstr("$>");
	*prompt = get_next_line(0);
	return (my_str_isnull(*prompt));
}
